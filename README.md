Pour générer l'exécutable : `make koch`

Pour l'exécuter : `./koch longeur_segment nb_iterations couleur_trace couleur_fond nom_fichier [all]`

Les couleurs sont en hexadécimal. `all` est un paramètre facultatif.

Exemples : 

* `./koch 1000 4 FF0000 FFFFFF test.ppm`
* `./koch 200 2 000000 FFFFFF test2.ppm all`

Comme expliqué dans l'énoncé, pour visionner l'image de rendu : `eog nom_fichier`
