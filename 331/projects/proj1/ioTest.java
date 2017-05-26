import java.io.File;


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.ByteArrayInputStream;


import java.io.InputStream;
import java.io.ByteArrayOutputStream;
import java.io.BufferedInputStream;
import java.util.Arrays;


public class ioTest
{

	public static short swap(short data)
	{
		int seg1 = data & 0xff;
		int seg2 = (data >>> 8) & 0xff;

		return (short) (seg1 << 8 | seg2 << 0);				
	}
	
	public static int swap(int data)
	{
		int seg1 = data & 0xff;
		int seg2 = (data >>> 8) & 0xff;
		int seg3 = (data >>> 16) & 0xff;
		int seg4 = (data >>> 24) & 0xff;
		
		return (int) (seg1 << 24 | seg2 << 16 | seg3 << 8 | seg4 << 0);
	}
	
	public static long swap(long data)
	{
		long seg1 = data & 0xff;
		long seg2 = (data >>> 8) & 0xff;
		long seg3 = (data >>> 16) & 0xff;
		long seg4 = (data >>> 24) & 0xff;
		long seg5 = (data >>> 32) & 0xff;
		long seg6 = (data >>> 40) & 0xff;
		long seg7 = (data >>> 48) & 0xff;
		long seg8 = (data >>> 56) & 0xff;
		
		return (long) (seg1 << 56 | seg2 << 48 | seg3 <<40 | seg4 << 32 
		| seg5 << 24 | seg6 << 16 | seg7 << 8 | seg8 << 0);						
	}
	
	public static float swap(float data)
	{
		int seg = Float.floatToIntBits(data);
		seg = swap(seg);
		return Float.intBitsToFloat(seg);
	}
	
	public static void swap(byte[] data)
	{
		if(data==null)
		{
			return;
		}
		int i = 0;
		int j = data.length-1;
		byte temp;
		while(i<j)
		{
			temp = data[j];
			data[j]=data[i];
			data[i]=temp;
			i++;
			j--;
		}
	}
	
	public static void main(String[] args) throws IOException
	{
	  //InputStream is = null;
      DataInputStream dis = null;
      FileInputStream beFile = new FileInputStream("EnGen.beFile");
	  byte id;
	  byte spare;
	  short length;
	  int seqNum;
	  long startTime;
	  float latitude;
	  float longitude;
	  float speed;
	  int samples;
	  short errorCode;
	 
	  short component;
	  int version;
	  byte[]operator = new byte[32];
	  String csv = "-csv";
	  
	  PrintWriter out = new PrintWriter("textfile.csv");
	  DataOutputStream dos = new DataOutputStream(new FileOutputStream("test.leFile"));
	  
         // create data input stream
         dis = new DataInputStream(beFile);
      
         // readBoolean till the data available to read
         while( dis.available() >0)
         {
            // read one single byte
            byte b = dis.readByte();
		
			int i = 0;
			switch(b)
			{
				case 100:
			
					
					spare = dis.readByte();
					length = dis.readShort();
					seqNum = dis.readInt();
					startTime = dis.readLong();
					latitude = dis.readFloat();
					longitude = dis.readFloat();
					i = dis.read(operator,0,32);					
					
					if(args[0].equals("beFile"))
					{
					dos.writeByte(b);
					dos.writeByte(spare);
					dos.writeShort(swap(length));
					dos.writeInt(swap(seqNum));
					dos.writeLong(swap(startTime));
					dos.writeFloat(swap(latitude));
					dos.writeFloat(swap(longitude));
					dos.write(operator);
					
					}		
					
					if(args[0].equals(csv))
					{					
					String readOper = new String(operator, "UTF-8");
					readOper = readOper.replaceAll("\\x00", "");
					out.write(b+","+spare+","+length+","+seqNum+","+startTime+","+latitude+","+longitude+",");
					
					out.write(readOper,0,readOper.length());
					out.write("\n");
					}
					
					
					break;
					
				case 112:
					
					spare = dis.readByte();
					length = dis.readShort();
					seqNum = dis.readInt();
					startTime = dis.readLong();
					speed = dis.readFloat();
					samples = dis.readInt();
					
					if(args[0].equals(csv))
					{
					out.write(b+","+spare+","+length+","+seqNum+","+startTime+","+speed+","+samples+"\n");
					
					}
					
					if(args[0].equals("beFile"))
					{
					dos.writeByte(b);
					dos.writeByte(spare);
					dos.writeShort(swap(length));
					dos.writeInt(swap(seqNum));
					dos.writeLong(swap(startTime));
					dos.writeFloat(swap(speed));
					dos.writeInt(swap(samples));
					
					}		
					break;
					
				case 120:
					
					spare = dis.readByte();
					length = dis.readShort();
					seqNum = dis.readInt();
					startTime = dis.readLong();
					errorCode = dis.readShort();
					component = dis.readShort();
					version = dis.readInt();
					
					if(args[0].equals(csv))
					{
					out.write(b+","+spare+","+length+","+seqNum+","+startTime+","+errorCode+","+component+","+version);
					}
					
					if(args[0].equals("beFile"))
					{
					dos.writeByte(b);
					dos.writeByte(spare);
					dos.writeShort(swap(length));
					dos.writeInt(swap(seqNum));
					dos.writeLong(swap(startTime));
					dos.writeShort(swap(errorCode));
					dos.writeShort(swap(component));
					dos.writeInt(swap(version));
					
					}		
					break;
				
				default:
				
					spare = dis.readByte();
					length = dis.readShort();
					dis.skipBytes(length-4);
					break;
					
			}
			
         }
		 out.close();
	}

}