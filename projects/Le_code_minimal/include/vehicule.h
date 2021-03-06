
#ifndef H_NJ_VEHICULE_261120071937
#define H_NJ_VEHICULE_261120071937

#include <glib-object.h>

#define TYPE_VEHICULE            (vehicule_get_type ())
#define VEHICULE(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_VEHICULE, Vehicule))
#define VEHICULE_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_VEHICULE, VehiculeClass))
#define IS_VEHICULE(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_VEHICULE))
#define IS_VEHICULE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_VEHICULE))
#define VEHICULE_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_VEHICULE, VehiculeClass))

typedef struct _Vehicule Vehicule;
typedef struct _VehiculeClass VehiculeClass;

struct _Vehicule
{
  GObject parent;
};

struct _VehiculeClass
{
  GObjectClass parent;
};

GType vehicule_get_type (void);

#endif /* H_NJ_VEHICULE_261120071937 */