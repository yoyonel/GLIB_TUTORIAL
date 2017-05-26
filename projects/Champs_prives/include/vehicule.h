
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

// Les méthodes publiques sont de simples fonctions externes. 
// Par convention, ces fonctions ont un nom qui commence par celui de la classe et leur premier argument est l'objet auquel doit s'appliquer la fonction. 
// C'est le this ou self passé implicitement dans langages orientés objets. 
extern void vehicule_show_vitesse (Vehicule *self);

// La structure parent doit toujours être le premier membre de la structure. 
// Nous ajoutons donc nos variables en dessous. 
struct _Vehicule
{
  GObject parent;

  /*< public >*/
  guint32 flags;
};

struct _VehiculeClass
{
  GObjectClass parent;
};


// Pour définir des variables privées, il ne suffit pas de déclarer une variables static, 
// puisque dans ce cas elle serait partagée par l'ensemble des instances d'une classe. 
// GObject propose un mécanisme qui permet à chaque objet de disposer de ses propres variables privées.
// Pour cela, il faut créer une structure qui regroupera l'ensemble des variables privées : 
typedef struct _VehiculePrivate VehiculePrivate;

struct _VehiculePrivate
{
  gint vitesse;
};


GType vehicule_get_type (void);

#endif /* H_NJ_VEHICULE_261120071937 */
