package app;

import java.io.FilterOutputStream;
import java.io.OutputStream;
import java.io.IOException;

public abstract class PrimOutputStream extends FilterOutputStream
{
   public PrimOutputStream(OutputStream out)
   {
      super(out);
   }

   // Provide write methods for all multi-byte primitive types

   public abstract void writeDouble(double v) throws IOException;

   public abstract void writeFloat(float v) throws IOException;

   public abstract void writeInt(int v) throws IOException;

   public abstract void writeLong(long v) throws IOException;

   public abstract void writeShort(int v) throws IOException;
}
