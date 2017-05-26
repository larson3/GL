package app;

import java.io.OutputStream;
import java.io.IOException;

class CsvOutputStream extends PrimOutputStream
{
   private boolean dirty;
   private boolean trailingComma;
   private boolean cleanString;

   public CsvOutputStream(OutputStream out, boolean trailingComma, 
                          boolean cleanString)
   {
      super(out);
      dirty = false;
      this.trailingComma = trailingComma; 
      this.cleanString   = cleanString;
   }

   public final void writeDouble(double v) throws IOException
   {
      writeString(Double.toString(v));
   }

   public final void writeFloat(float v) throws IOException
   {
      writeString(Float.toString(v));
   }

   public final void writeInt(int v) throws IOException
   {
      writeString(Integer.toString(v));
   }

   public final void writeLong(long v) throws IOException
   {
      writeString(Long.toString(v));
   }

   public final void writeShort(int v) throws IOException
   {
      writeString(Integer.toString(v));
   }

   // override write() methods so byte is output as a string

   public final void write(int b) throws IOException
   {
      writeInt(b & 0xFF);
   }

   public final void write(byte[] b) throws IOException
   {
      write(b,0,b.length);
   }

   public final void write(byte[] b, int off, int len) throws IOException
   {
      if (cleanString)
      {
         // Shorten len if there are any zero-valued bytes in b 
         // (for clean text output)
         int i = off;
         while (i < len && b[i] != 0) ++i; 
         len = i;
      }
      writeString(new String(b,off,len));      
   }

   // override flush() method to insert a new line per CSV format
   
   public final void flush() throws IOException
   {
      if (dirty)
      {
         // clear dirty bit so a comma is not inserted prior to newline
         if (!trailingComma) dirty = false;
         writeString("\n");
         dirty = false;
      }
      super.flush();
   }

   private void writeString(String s) throws IOException
   {
      if (dirty) out.write(",".getBytes());
      out.write(s.getBytes());
      dirty = true;
   }
}
