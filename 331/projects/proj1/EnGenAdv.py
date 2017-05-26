# EnGenAdv - Advanced Endian Generator for Assignment #1
#
# This is the advanced version of the EnGen.py Python program.  It has
# all of the features of EnGen.py plus features for generating additional
# test files.  The new features are:
#
#  1. Includes a fourth, "unknown" message for Extra Credit option.
#
#     [pond@linux3 01] python EnGenAdv.py -ec
#
#  2.  TBD
#
# This script generates binary big-endian and little-endian files of the
# same message content.  The resulting files can be used to test your
# Assignment #1 for correct behavior.  That is, use your program to convert
# the generated big-endian file to little-endian.  And then compare your 
# little-endian file to the little-endian file generated by this script.
#
# For example,
#
#  [pond@linux3 01] python EnGenAdv.py
#  [pond@linux3 01] java Assign01 EnGenAdv.beFile outputFile
#  [pond@linux3 01] diff outputFile EnGenAdv.leFile
#
# The "diff" command compares two files and tells you if the files differ.
# If the files match, diff outputs nothing.  If there is a mismatch, diff
# outputs "Binary files outputFile and EnGenAdv.leFile differ" which, in your
# case, means that your program has a bug.
#

import struct
import sys

class Message(object):
   def __init__(self, **kwds):
      self.__dict__.update(kwds)

def main():

   ecEnabled = False
   if (len(sys.argv) >= 2):
      ecEnabled = (sys.argv[1] == "-ec")

   beFile = open("EnGenAdv.beFile","wb")
   leFile = open("EnGenAdv.leFile","wb")

   eList = [ (beFile, ">"), (leFile, "<") ]

   setup = Message(id         = 100,
                   length     =  56,
                   seq_num    =   1,
                   start_time = 123456789987654321,
                   latitude   =  34.123,
                   longitude  = -77.123,
                   operator   = "Rory")
 
   data  = Message(id         = 112,
                   length     =  24,
                   seq_num    =   2,
                   start_time = 123456789987655931,
                   speed      =  64.123,
                   samples    =   4)
 
   status =Message(id         = 120,
                   length     =  24,
                   seq_num    =   3,
                   start_time = 123456789987990125,
                   error_code = 0xdead,
                   component  = 0xbeef,
                   version    = 0x02010009)
 
   unknown=Message(id         =   7,
                   length     =  44,
                   seq_num    =   4,
                   payload    = "Legacy message which has been deprecated")
 
   for e in eList:
      e[0].write(struct.pack(e[1]+"BBHIQff32s",
                 setup.id,
                 0,
                 setup.length,
                 setup.seq_num,
                 setup.start_time,
                 setup.latitude,
                 setup.longitude,
                 setup.operator))
      e[0].write(struct.pack(e[1]+"BBHIQfI",
                 data.id,
                 0,
                 data.length,
                 data.seq_num,
                 data.start_time,
                 data.speed,
                 data.samples))
      e[0].write(struct.pack(e[1]+"BBHIQHHI",
                 status.id,
                 0,
                 status.length,
                 status.seq_num,
                 status.start_time,
                 status.error_code,
                 status.component,
                 status.version))
      if (ecEnabled):
         e[0].write(struct.pack(e[1]+"BBH40s",
                    unknown.id,
                    0,
                    unknown.length,
                    unknown.payload))

   beFile.close()
   leFile.close()

main()