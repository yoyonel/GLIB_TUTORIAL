#include "vehicule.h"

int main (void)
{
    Vehicule *v = NULL;

    v = g_object_new (TYPE_VEHICULE, NULL);

    // Pour accéder à notre variable, nous devons récupérer notre classe.
    // Si nous en possédons une instance, rien de plus simple, il suffit d'utiliser la macro que nous avons écrite au dessus :
    VehiculeClass *klass = VEHICULE_GET_CLASS (v);
    // il est aussi possible d'obtenir notre classe en l'absence d'instance de celle-ci (c'est la définition même des membres statiques).
    // Pour ce faire, il suffit d'utiliser la fonction g_type_class_peek :
    // VehiculeClass *klass = g_type_class_peek (TYPE_VEHICULE);

    klass->static_integer = 42*2;

    g_print ("klass->static_integer=%d\n", klass->static_integer);

    g_object_unref (v);

    return 0;
}
