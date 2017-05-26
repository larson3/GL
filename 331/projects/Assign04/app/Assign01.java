package app;

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.EOFException;
import java.io.FileNotFoundException;

class Assign01
{
	
   private static void usage()
   {
	   
      System.out.println("usage: java Assign01 [-count] [-csv]" +
                         " infile outfile");
   }

   public static void main(String[] args)
   {
	   
      boolean countEnabled = false;
      boolean csvEnabled = false;
      String infileName = null;
      String outfileName = null;

      int i = 0;
      if (i < args.length && args[i].equals("-count"))
      {
         countEnabled = true;
         ++i;
      }
      if (i < args.length && args[i].equals("-csv"))
      {
         csvEnabled = true;
         ++i;
      }
      if (i < args.length && args[i].equals("-ss"))
      {
         // Use signed short reads (allowed behavior but not preferred)
         useUnsigned = false;
         ++i;
      }
      if (i < args.length && args[i].equals("-kt"))
      {
         // Keep truncated messages (allowed behavior but not preferred)
         discardTrunc = false;
         ++i;
      }
      if (i < args.length && args[i].equals("-nt"))
      {
         // No trailing comma (allowed behavior but not preferred)
         trailingComma = false;
         ++i;
      }
      if (i < args.length && args[i].equals("-cs"))
      {
         // Clean string (allowed behavior but not preferred)
         cleanString = false;
         ++i;
      }
      if (i < args.length)
      {
         infileName = args[i];
         ++i;
      }
      if (i < args.length)
      {
         outfileName = args[i];
         ++i;
      }
      if (infileName != null && outfileName != null)
      {
         Assign01 assign01 = new Assign01();
         assign01.Convert(countEnabled,csvEnabled,infileName,outfileName);
      }
      else
      {
         usage();
      }
   }

   void Convert(boolean showCount, boolean csvEnabled, 
                String inFile, String outFile)
   {
      DataInputStream  dis = null;
      PrimOutputStream pos = null;

      try
      {
         dis = new DataInputStream(new FileInputStream(inFile));
         if (csvEnabled)
         {
            pos = new CsvOutputStream(new FileOutputStream(outFile),
                                      trailingComma,cleanString);
         }
         else
         {
            pos = new LeOutputStream(new FileOutputStream(outFile));
         }

         for(;;)
         {
            switch (dis.readByte())
            {
               case 100:
                  ConvertSetup(dis,pos);
                  break;

               case 112:
                  ConvertData(dis,pos);
                  break;

               case 120:
                  ConvertStatus(dis,pos);
                  break;

               default:
                  SkipUnknown(dis);
                  break;
            }
         }
      }
      catch (EOFException ex)
      {
         // Normal ending; handle silently
      }
      catch (FileNotFoundException ex)
      {
         System.out.println("File not found: " + inFile);
      }
      catch (IOException ex)
      {
         System.out.println("File not converted due to " + ex);
      }
   
      try
      {
         if (dis != null)
         {
            dis.close();
         }
      }
      catch (IOException ex)
      {
         // Don't care if close fails
      }

      try
      {
         if (pos != null)
         {
           pos.close();
         }
      }
      catch (IOException ex)
      {
         // Don't care if close fails
      }

      if (showCount)
      {
         System.out.println("Message counts:" + 
                            "  Setup "   + NumSetupMsg +
                            ", Data "    + NumDataMsg +
                            ", Status "  + NumStatusMsg +
                            ", Unknown " + NumUnkMsg);
      }
   }

   private void ConvertSetup(DataInputStream dis, PrimOutputStream pos)
      throws IOException
   {
      byte[] operator  = new byte[32];
      if (discardTrunc)
      {
         // Read all fields first so nothing is written if 
         // EOF encountered.
         byte  id         = 100;
         byte  spare      = dis.readByte();
         int   length     = read16Bit(dis);
         int   seq_num    = dis.readInt();
         long  start_time = dis.readLong();
         float latitude   = dis.readFloat();
         float longitude  = dis.readFloat();
         dis.readFully(operator);

         pos.write     (id);
         pos.write     (spare);
         pos.writeShort(length);
         pos.writeInt  (seq_num);
         pos.writeLong (start_time);
         pos.writeFloat(latitude);
         pos.writeFloat(longitude);
         pos.write     (operator);
      }
      else
      {
         pos.write     (100);                      // id
         pos.write     (dis.readByte());           // spare
         pos.writeShort(read16Bit(dis));  // length
         pos.writeInt  (dis.readInt());            // seq_num
         pos.writeLong (dis.readLong());           // start_time
         pos.writeFloat(dis.readFloat());          // latitude
         pos.writeFloat(dis.readFloat());          // longitude
         dis.readFully (operator);
         pos.write     (operator);
      }
      pos.flush();
      ++NumSetupMsg;
   }

   private void ConvertData(DataInputStream dis, PrimOutputStream pos)
      throws IOException
   {
      if (discardTrunc)
      {
         // Read all fields first so nothing is written if EOF encountered.
         byte  id         = 112;
         byte  spare      = dis.readByte();
         int   length     = read16Bit(dis);
         int   seq_num    = dis.readInt();
         long  start_time = dis.readLong();
         float speed      = dis.readFloat();
         int   samples    = dis.readInt();

         pos.write     (id);
         pos.write     (spare);
         pos.writeShort(length);
         pos.writeInt  (seq_num);
         pos.writeLong (start_time);
         pos.writeFloat(speed);
         pos.writeInt  (samples);
      }
      else // copy over fields in trucated messages
      {
         pos.write     (112);                      // id
         pos.write     (dis.readByte());           // spare
         pos.writeShort(read16Bit(dis));  // length
         pos.writeInt  (dis.readInt());            // seq_num
         pos.writeLong (dis.readLong());           // start_time
         pos.writeFloat(dis.readFloat());          // speed
         pos.writeInt  (dis.readInt());            // samples
      }
      pos.flush();
      ++NumDataMsg;
   }

   private void ConvertStatus(DataInputStream dis, PrimOutputStream pos)
      throws IOException
   {
      if (discardTrunc)
      {
         // Read all fields first so nothing is written if EOF encountered.
         byte  id         = 120;
         byte  spare      = dis.readByte();
         int   length     = read16Bit(dis);
         int   seq_num    = dis.readInt();
         long  start_time = dis.readLong();
         int   error_code = read16Bit(dis);
         int   component  = read16Bit(dis);
         int   version    = dis.readInt();

         pos.write     (id);
         pos.write     (spare);
         pos.writeShort(length);
         pos.writeInt  (seq_num);
         pos.writeLong (start_time);
         pos.writeShort(error_code);
         pos.writeShort(component);
         pos.writeInt  (version);
      }
      else // copy over fields in trucated messages
      {
         pos.write     (120);                      // id
         pos.write     (dis.readByte());           // spare
         pos.writeShort(read16Bit(dis));  // length
         pos.writeInt  (dis.readInt());            // seq_num
         pos.writeLong (dis.readLong());           // start_time
         pos.writeShort(read16Bit(dis));  // error_code
         pos.writeShort(read16Bit(dis));  // component
         pos.writeInt  (dis.readInt());            // version
      }
      pos.flush();
      ++NumStatusMsg;
   }

   // Extra credit method
   private void SkipUnknown(DataInputStream dis)
      throws IOException
   {
      // skip spare byte
      dis.readByte();

      // get length
      short length = (short) dis.readShort();

      // first four bytes (of message header) have already been read
      length -= 4;

      // discard rest of message
      byte[] b = new byte[length];
      if (dis.read(b) == length) 
      {
         ++NumUnkMsg;
      }
      else
      {
         throw new IOException("Unknown message truncated");
      }
   }

   private int read16Bit(DataInputStream dis) throws IOException
   {
      if (useUnsigned)
      {
         return dis.readUnsignedShort();
      }
      else
      {
         return dis.readShort();
      }
   }

   private int NumSetupMsg;
   private int NumDataMsg;
   private int NumStatusMsg;
   private int NumUnkMsg;

   // Flags to customizer behavior to match student's programs.  Defaulted
   // to preferred behavior.
   private static boolean discardTrunc  = true;
   private static boolean useUnsigned   = true;
   private static boolean trailingComma = true;
   private static boolean cleanString   = true;
}
