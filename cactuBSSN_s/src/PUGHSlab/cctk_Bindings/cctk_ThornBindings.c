#include <stdio.h>

#include "cctki_ActiveThorns.h"

void CCTKi_BindingsThorn_PUGHSlab(void);
void CCTKi_BindingsThorn_PUGHSlab(void)
{
  const char *name[] = {"PUGHSlab", 0};
  const char *implementation[] = {"Hyperslab", 0};
  const char *activates_thorns[] =
  {
    "PUGH",
    0,
  };

  /*
   * Should be able to do below with a constant initializer
   * but sr8000 compiler doesn't like it.
   * So have to laboriously assign values to each member of array.
   */
  struct iAttributeList attributes[4];

  attributes[0].attribute                = "name";
  attributes[0].AttributeData.StringList = name;
  attributes[1].attribute                = "implementation";
  attributes[1].AttributeData.StringList = implementation;
  attributes[2].attribute                = "activates thorns";
  attributes[2].AttributeData.StringList = activates_thorns;
  attributes[3].attribute                = 0;
  attributes[3].AttributeData.StringList = 0;

  CCTKi_RegisterThorn(attributes);
}
