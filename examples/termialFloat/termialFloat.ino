//
//    FILE: termialFloat.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo difference termial and termialFloat for real numbers.
//     URL: https://github.com/RobTillaart/statHelpers
//
//  best viewed in Serial plotter

#include "statHelpers.h"
#include "printHelpers.h"  //  to print large numbers....


uint32_t start, duration1, duration2;


void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println(__FILE__);
  Serial.print("STATHELPERS_LIB_VERSION: ");
  Serial.println(STATHELPERS_LIB_VERSION);
  Serial.println();

  for (float n = 1; n <= 51; n += 0.1)
  {
    Serial.print(termial(n));
    Serial.print('\t');
    Serial.print(termialFloat(n));
    Serial.println();
  }
  Serial.println();
}


void loop()
{
}


//  -- END OF FILE --
