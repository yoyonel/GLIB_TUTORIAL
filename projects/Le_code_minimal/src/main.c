#include "vehicule.h"

int main (void)
{
  Vehicule *v = NULL;
  // warning: ‘g_type_init’ is deprecated [-Wdeprecated-declarations]
  // g_type_init ();
  v = g_object_new (TYPE_VEHICULE, NULL);  
  g_object_unref (v);

  return 0;
}
