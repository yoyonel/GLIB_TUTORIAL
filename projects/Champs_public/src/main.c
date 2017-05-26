#include "vehicule.h"

int main (void)
{
  Vehicule *v = NULL;

  v = g_object_new (TYPE_VEHICULE, NULL);

  // Pour accéder à notre champ, il suffit de procéder comme pour une structure classique :
  v->flags = 42;
  g_print ("v->flags = %d\n", v->flags);

  g_object_unref (v);
  return 0;
}
