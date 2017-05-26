
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

extern void vehicule_show_vitesse (Vehicule *self);

struct _Vehicule
{
    GObject parent;

    /*< public >*/
    guint32 flags;
};

struct _VehiculeClass
{
    GObjectClass parent;

    gint static_integer;

    // Pour créer une méthode virtuelle, il faut commencer par déclarer un pointeur de fonction dans notre classe :
    void (* avancer) (Vehicule *self, gint distance);
};

typedef struct _VehiculePrivate VehiculePrivate;

struct _VehiculePrivate
{
    gint vitesse;
};


GType vehicule_get_type (void);

void vehicule_avancer (Vehicule *self, gint distance);
void vehicule_avancer_2 (Vehicule *self, gint distance);

#endif /* H_NJ_VEHICULE_261120071937 */
