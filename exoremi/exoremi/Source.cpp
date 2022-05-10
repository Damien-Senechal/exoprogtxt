#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>

//Fonction qui ecrit les donn�e d'une map dans un fichier texte
void WriteTxt(std::map<char, int> Mymap) {

    //on cr�e un flux sortant
    std::ofstream text;

    //On ouvre le fichier Occurences.txt, si il n'existe pas il est cr�e
    text.open("Occurrences.txt");
    //Si le texte a reussi a etre ouvert on ecrit dans texte les donn�es de la map
    if (text) {
        text << "Les occurrences demand�s : " << std::endl;
        for (std::map<char, int>::iterator it = Mymap.begin(); it != Mymap.end(); it++) {
            text << "le nombre d'occurence du mot " << it->first << " est " << it->second << std::endl;
        }
    }
    //Si on arrive pas a ouvrir le texte on affiche erreur
    else {
        std::cout << "erreur";
    }
}

int main()
{
    //On cr�e un flux entrant
    std::ifstream ifs("test.txt");
    //Une variable de type char
    char s;
    //Une map qui contient des char avec un int
    std::map<char, int> map;

    //Tant qu'il reste des caractere a lire on les ajoute dans la map
    //La map va trier, ranger et compter les char qu'on lui donne
    while (ifs >> s)
        ++map[s];

    //On ecrit ensuite les occurences trouv� dans un fichier texte avec la fonction suivante
    WriteTxt(map);

    return 0;
}
