#include "vehicule.h"

int main (void)
{
  Vehicule *v = NULL;

  //  warning: ‘g_type_init’ is deprecated
  // g_type_init ();

  v = g_object_new (TYPE_VEHICULE, NULL);

  // Pour accéder à notre champ, il suffit de procéder comme pour une structure classique :
  v->flags = 42;
  g_print ("[public] v->flags = %d\n", v->flags);

  // private method
  // ne fonctionne pas car 'private'
  // plus précisement, c'est une méthode 'static'
  // donc non accessible de l'extérieur (de vehicule.c)
  // vehicule_reset_flags (v);  // ERROR: main.c:(.text+0x62): undefined reference to `vehicule_reset_flags'

  // public method (with private member)
  vehicule_show_vitesse (v);

  g_object_unref (v);

  return 0;
}
