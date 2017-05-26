#include "vehicule.h"

GType vehicule_get_type (void)
{
  static GType type = 0;

  if (type == 0)
  {
    static const GTypeInfo info = {
      sizeof (VehiculeClass), /* class_size */
      NULL,                   /* base_init */
      NULL,                   /* base_finalize */
      NULL,                   /* class_init */
      NULL,                   /* class_finalize */
      NULL,                   /* class_data */
      sizeof (Vehicule),      /* instance_size */
      0,                      /* n_preallocs */
      NULL,                   /* instance_init */
      NULL                    /* value_table */
    };
    type = g_type_register_static (G_TYPE_OBJECT, "Vehicule", &info, 0);
  }
  return type;
}
