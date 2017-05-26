#include "vehicule.h"

G_DEFINE_TYPE (Vehicule, vehicule, G_TYPE_OBJECT)

static void vehicule_class_init (VehiculeClass *klass)
{
  g_return_if_fail (klass != NULL);
}

static void vehicule_init (Vehicule *self)
{
  g_return_if_fail (self != NULL);
}
