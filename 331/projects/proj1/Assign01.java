/******************************************************************************
*
* File:    Assign01.java
* Project: CMSC 311 Project 1, Spring 2015
* Author:  John Larson
* Date:    02/28/2015
*
* E-mail:  larson3@umbc.edu 
*
*   This file contains the main logic for the Assign01 class
*
******************************************************************************/


import java.io.PrintWriter;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.DataOutputStream;
import java.io.DataInputStream;
import java.io.EOFException;

public class Assign01
{

/****************************************************************
 * swap(short):
 * Preconditions: 
 *	  valid short
 * Postconditions:
 *   This method swaps bytes from LE to BE or the other way around 
 *   for an short (16 bits)
 ****************************************************************/
	public static short swap(short data)
	{
		int seg1 = data & 0xff;
		int seg2 = (data >>> 8) & 0xff;

		return (short) (seg1 << 8 | seg2 << 0);				
	}
	
/****************************************************************
 * swap(int):
 * Preconditions: 
 *	  valid int
 * Postconditions:
 *   This method swaps bytes from LE to BE or the other way around 
 *   for an int (32 bits)
 ****************************************************************/
	public static int swap(int data)
	{
		int seg1 = data & 0xff;
		int seg2 = (data >>> 8) & 0xff;
		int seg3 = (data >>> 16) & 0xff;
		int seg4 = (data >>> 24) & 0xff;
		
		return (int) (seg1 << 24 | seg2 << 16 | seg3 << 8 | seg4 << 0);
	}

/****************************************************************
 * swap(long):
 * Preconditions: 
 *	  valid long
 * Postconditions:
 *   This method swaps bytes from LE to BE or the other way around 
 *   for a long (64-bits)
 ****************************************************************/
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
	
/****************************************************************
 * swap(float):
 * Preconditions: 
 *	  valid float
 * Postconditions:
 *   This method swaps bytes from LE to BE or the other way around 
 *   for a float.  It will do this by casting the float as an int and
 *   then calling the int swap method
 ****************************************************************/
	public static float swap(float data)
	{
		int seg = Float.floatToIntBits(data);
		seg = swap(seg);
		return Float.intBitsToFloat(seg);
	}
	
/****************************************************************
 * swap(byte[]):
 * Preconditions: 
 *	  valid byte array
 * Postconditions:
 *   This method swaps bytes from LE to BE or the other way around 
 *   for a byte array.  The program won't use this but I am proud of the
 *   logic so I'm keeping it.
 ****************************************************************/
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
			//what this is doing is treating the byte array as a dequeue
			//and is swapping from both ends simultaneously
			temp = data[j];
			data[j]=data[i];
			data[i]=temp;
			i++;
			j--;
		}
	}
	
	public static void main(String[] args) throws IOException
	{

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
	  int setupCt=0;
	  int dataCt = 0;
	  int statusCt = 0;
	 
	  short component;
	  int version;
	  byte[]operator = new byte[32];
	  String csv = "-csv";
	  String inputName;
	  String outputName;
	  
	  //these if statements are simply checking what the user wants the 
	  //program to do from the command line args
	  //sometimes the user puts in nothing
	  if(args.length == 0)
	  {
		  System.out.println("Please specify input/output files");
		  System.exit(0);
	  }
	  
	  if(args[0].equals("-count"))
	  {
		  inputName = args[1];
		  outputName = args[2];
	  }
	  else if(args[0].equals("-csv"))
	  {
		  inputName = args[1];
		  outputName = args[2];
	  }
	  else
	  {
		  inputName = args[0];
		  outputName = args[1];
	  }
	  //the user might put in bad info, this will catch it and show the
	  //user exactly what they put in incorrectly
	  try
	  {
		  FileInputStream test = new FileInputStream(inputName);
		  test.close();
	  }
	  catch (IOException e)
	  {
			System.err.println("Bad input file : "+e.getMessage());
			//want to leave the program entirely
			//want to leave the program entirely
			System.exit(0);
	  }
		DataInputStream dis = null;
		FileInputStream beFile = new FileInputStream(inputName);
		dis = new DataInputStream(beFile);
		PrintWriter out = new PrintWriter(outputName);
		DataOutputStream dos = new DataOutputStream(new FileOutputStream(outputName));
	    
        
      
         // read until we run out of bytes
         while( dis.available() >0)
         {
            // read one single byte
            byte b = dis.readByte();
		
			int i = 0;
			switch(b)
			{
				//this is a setup message
				case 100:
			
					//the xxxCt ints just track how many instances of
					//each case we see
					try
					{
						setupCt++;
						spare = dis.readByte();
						length = dis.readShort();
						seqNum = dis.readInt();
						startTime = dis.readLong();
						latitude = dis.readFloat();
						longitude = dis.readFloat();
						i = dis.read(operator,0,32);
					}
					catch(EOFException e1)
					{
						break;
					}
					
					//this will output the data to a .txt file and will be 
					//readable to humans
					if(args[0].equals(csv))
					{					
					String readOper = new String(operator, "UTF-8");
					readOper = readOper.replaceAll("\\x00", "");
					out.write(b+","+spare+","+length+","+seqNum+","+startTime+","+latitude+","+longitude+",");
					
					//this one is tricky because it's hard to write the byte array
					//so we have to do this one separately
					out.write(readOper,0,readOper.length());
					out.write("\n");
					}
					
					//writing reversed bytes to a new file in binary
					else
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
					
					
					
					
					break;
					
				case 112:
					//112 and 120 are just like 100
					try
					{
					dataCt++;
					spare = dis.readByte();
					length = dis.readShort();
					seqNum = dis.readInt();
					startTime = dis.readLong();
					speed = dis.readFloat();
					samples = dis.readInt();
					}
					catch(EOFException e1)
					{
						break;
					}
					if(args[0].equals(csv))
					{
					out.write(b+","+spare+","+length+","+seqNum+","+startTime+","+speed+","+samples+"\n");
					
					}
					
					else
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
					try
					{
						statusCt++;
						spare = dis.readByte();
						length = dis.readShort();
						seqNum = dis.readInt();
						startTime = dis.readLong();
						errorCode = dis.readShort();
						component = dis.readShort();
						version = dis.readInt();
					}
					catch(EOFException e1)
					{
						break;
					}
					if(args[0].equals(csv))
					{
					out.write(b+","+spare+","+length+","+seqNum+","+startTime+","+errorCode+","+component+","+version);
					}
					
					else
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
					try
					{
					//in the case of a first byte which is unaccounted for
					spare = dis.readByte();
					length = dis.readShort();
					//the name, spare and length total 4 bytes, so we go the length
					//minus the 4 bytes we have already passed
					dis.skipBytes(length-4);
					}
					catch(EOFException e1)
					{
						break;
					}
					break;
					
			}
			
         }
		 out.close();
		 //if the user wanted a count we give it
		 if(args[0].equals("-count"))
		{
			System.out.println("Setup "+setupCt+", Data "+dataCt+", Status "+statusCt);
		}
	}
	
}