# IN104_TREYER_ELLERBACH

# IN104
Les algorithme que nous avons construit fonctionne avec des mots en MAJUSCULE, et SANS ACCENT.
Dans le main.c vous trouverez toutes les fonctionnalité que nous avons developpé dans le cadre du projet d'analyse et de réslution du jeu wordle

Pour faire fonctionner notre programme, veuillez compiler avec la commande suivante :
gcc -Wall -Werror -Wfatal-errors jeu_auto.c  resolve.c -lm jeu_auto_naif.c jeu.c tools.c load_file.c main.c
Ensuite exéctuer a.out en ajoutant en argument le nom du dictionnaire que vous voulez utiliser. Par exemple :
./a.out dico.txt


Il est aussi possible de construire des dictionnaires avec seulement des mots d'une certaine taille (cela était utile au début mais ce programme est maintenant obselète : le main prend en argument un dictionnaire quelconque et extrait lui meme les mots de la bonne taille)
pour cela utilsier la commande :
gcc -Wall -Werror -Wfatal-errors dicoreduit.c
Ensuite executeé en metant le nom de votre dictionnaire en argument comme précédement :
./a.out dico.txt


Le but et le role de chaque fonction a été commenté pour plus de lisibilité. De plus de nombreux printf sont en commentaire dans le code, libre à vous de les ajouter au code pour mieux comprendre ou faire des tests sur l'algorithme.
Aussi il est conseillé de retirer les printf de jeu_auto.c ou jeu_auto_naif.c si vous voulez effectuer un grand nombre de simulation pour plus d'efficacité