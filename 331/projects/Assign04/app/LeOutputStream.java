package app;

import java.io.OutputStream;
import java.io.IOException;

class LeOutputStream extends PrimOutputStream
{
   public LeOutputStream(OutputStream out)
   {
      super(out);
   }

   public final void writeDouble(double v) throws IOException
   {
      writeLong(Double.doubleToLongBits(v));
   }

   public final void writeFloat(float v) throws IOException
   {
      writeInt(Float.floatToIntBits(v));
   }

   public final void writeInt(int v) throws IOException
   {
      // Write little end, i.e., the lower byte, first, et al
      write( v         & 0x000000FF);
      write((v  >>  8) & 0x000000FF);
      write((v  >> 16) & 0x000000FF);
      write( v >>> 24);
   }

   public final void writeLong(long v) throws IOException
   {
      // Write little end, i.e., the lower byte, first, et al
      write((int)( v         & 0x00000000000000FFL));
      write((int)((v  >>  8) & 0x00000000000000FFL));
      write((int)((v  >> 16) & 0x00000000000000FFL));
      write((int)((v  >> 24) & 0x00000000000000FFL));
      write((int)((v  >> 32) & 0x00000000000000FFL));
      write((int)((v  >> 40) & 0x00000000000000FFL));
      write((int)((v  >> 48) & 0x00000000000000FFL));
      write((int)( v >>> 56));
   }

   public final void writeShort(int v) throws IOException
   {
      // Write little end, i.e., the lower byte, first, et al
      write(v & 0x000000FF);
      write(v >>> 8);
   }
}
