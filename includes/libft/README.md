<div id="header" align="center">
  <img src="https://media.giphy.com/media/ztl9x7JlhSlU4MWD6h/giphy.gif" width="200"/>
</div>

<h1 align="center">libft</h1>

> Projet du cursus de l'école 42 Paris

Ce dépôt contient tous les fichiers du projet __libft__ dans le __cursus principal de l'école 42 Paris__. C'est une bibliothèque personnalisée de fonctions utiles en __langage C__. Le dépôt inclut le `Makefile` et la bibliothèque `libft.h`.

<h2 align="center">
	<a href="#about">À propos</a>
	<span> · </span>
	<a href="#index">Index</a>
	<span> · </span>
	<a href="#requirements">Exigences</a>
	<span> · </span>
	<a href="#instructions">Instructions</a>
	<span> · </span>
	<a href="#testing">Tests</a>
</h2>

## À propos

Ce projet est une __bibliothèque C__ de fonctions utiles qui peuvent être utilisées dans les projets futurs du __cursus de l'école 42__. Avec l'accès à cette bibliothèque, le processus de codage dans les projets à venir sera plus efficace. L'objectif de réécrire ces fonctions est de mieux les comprendre et d'acquérir une large gamme d'outils pour les prochains projets. [Tu peux trouver plus d'informations dans le sujet ici](https://github.com/Jyzdcs/libft/blob/main/fr.subject.pdf). Comme indiqué dans le sujet, tous les fichiers se trouvent dans le même dossier.

Le code dans ce dépôt suit [les règles de la Norminette](https://github.com/Jyzdcs/libft/blob/main/norme.es.pdf).

## Index
### Fonctions de la bibliothèque `<ctype.h>`
* [`ft_isascii`](https://github.com/Jyzdcs/libft/blob/main/ft_isascii.c) - Vérifie si un caractère est un caractère ASCII 7 bits.
* [`ft_isalpha`](https://github.com/Jyzdcs/libft/blob/main/ft_isalpha.c) - Vérifie si un caractère est alphabétique.
* [`ft_isdigit`](https://github.com/Jyzdcs/libft/blob/main/ft_isdigit.c) - Vérifie si un caractère est un chiffre décimal.
* [`ft_isalnum`](https://github.com/Jyzdcs/libft/blob/main/ft_isalnum.c) - Vérifie si un caractère est alphanumérique.
* [`ft_isprint`](https://github.com/Jyzdcs/libft/blob/main/ft_isprint.c) - Vérifie si un caractère est imprimable, y compris un espace.
* [`ft_tolower`](https://github.com/Jyzdcs/libft/blob/main/ft_tolower.c) - Convertit un caractère en minuscule.
* [`ft_toupper`](https://github.com/Jyzdcs/libft/blob/main/ft_toupper.c) - Convertit un caractère en majuscule.

### Fonctions de la bibliothèque `<stdlib.h>`
* [`ft_atoi`](https://github.com/Jyzdcs/libft/blob/main/ft_atoi.c) - Convertit une chaîne ASCII en entier.
* [`ft_calloc`](https://github.com/Jyzdcs/libft/blob/main/ft_calloc.c) - Alloue de l'espace pour un tableau et l'initialise à 0.

### Fonctions de la bibliothèque `<strings.h>`
* [`ft_bzero`](https://github.com/Jyzdcs/libft/blob/main/ft_bzero.c) - Remplit les premiers octets d'un objet avec des zéros.
* [`ft_memset`](https://github.com/Jyzdcs/libft/blob/main/ft_memset.c) - Remplit la mémoire avec une valeur donnée.
* [`ft_memchr`](https://github.com/Jyzdcs/libft/blob/main/ft_memchr.c) - Trouve la première occurrence d'un caractère dans un tampon.
* [`ft_memcmp`](https://github.com/Jyzdcs/libft/blob/main/ft_memcmp.c) - Compare les octets dans deux tampons.
* [`ft_memmove`](https://github.com/Jyzdcs/libft/blob/main/ft_memmove.c) - Copie des octets d'un tampon à un autre, en gérant correctement la mémoire chevauchante.
* [`ft_memcpy`](https://github.com/Jyzdcs/libft/blob/main/ft_memcpy.c) - Copie des octets d'un tampon à un autre.

### Fonctions de la bibliothèque `<string.h>`
* [`ft_strlen`](https://github.com/Jyzdcs/libft/blob/main/ft_strlen.c) - Obtient la longueur d'une chaîne.
* [`ft_strchr`](https://github.com/Jyzdcs/libft/blob/main/ft_strchr.c) - Trouve la première occurrence d'un caractère dans une chaîne.
* [`ft_strrchr`](https://github.com/Jyzdcs/libft/blob/main/ft_strrchr.c) - Trouve la dernière occurrence d'un caractère dans une chaîne.
* [`ft_strnstr`](https://github.com/Jyzdcs/libft/blob/main/ft_strnstr.c) - Localise une sous-chaîne dans une chaîne.
* [`ft_strncmp`](https://github.com/Jyzdcs/libft/blob/main/ft_strncmp.c) - Compare deux chaînes, jusqu'à une longueur donnée.
* [`ft_strdup`](https://github.com/Jyzdcs/libft/blob/main/ft_strdup.c) - Crée un duplicata d'une chaîne avec `malloc`.
* [`ft_strlcpy`](https://github.com/Jyzdcs/libft/blob/main/ft_strlcpy.c) - Copie une chaîne avec une taille maximale.
* [`ft_strlcat`](https://github.com/Jyzdcs/libft/blob/main/ft_strlcat.c) - Concatène une chaîne avec une taille maximale.

### Fonctions non standard
* [`ft_itoa`](https://github.com/Jyzdcs/libft/blob/main/ft_itoa.c) - Convertit un entier en chaîne ASCII.
* [`ft_substr`](https://github.com/Jyzdcs/libft/blob/main/ft_substr.c) - Obtient une sous-chaîne d'une chaîne.
* [`ft_strtrim`](https://github.com/Jyzdcs/libft/blob/main/ft_strtrim.c) - Supprime les caractères de début et de fin d'une chaîne.
* [`ft_strjoin`](https://github.com/Jyzdcs/libft/blob/main/ft_strjoin.c) - Concatène deux chaînes dans une nouvelle chaîne, en utilisant `calloc`.
* [`ft_split`](https://github.com/Jyzdcs/libft/blob/main/ft_split.c) - Divise une chaîne avec un caractère spécifique comme délimiteur.
* [`ft_strmapi`](https://github.com/Jyzdcs/libft/blob/main/ft_strmapi.c) - Crée une nouvelle chaîne modifiée par une fonction donnée.
* [`ft_striteri`](https://github.com/Jyzdcs/libft/blob/main/ft_striteri.c) - Modifie une chaîne avec une fonction donnée.
* [`ft_putchar_fd`](https://github.com/Jyzdcs/libft/blob/main/ft_putchar_fd.c) - Affiche un caractère dans un fichier donné.
* [`ft_putstr_fd`](https://github.com/Jyzdcs/libft/blob/main/ft_putstr_fd.c) - Affiche une chaîne dans un fichier donné.
* [`ft_putendl_fd`](https://github.com/Jyzdcs/libft/blob/main/ft_putendl_fd.c) - Affiche une chaîne dans un fichier donné avec un saut de ligne.
* [`ft_putnbr_fd`](https://github.com/Jyzdcs/libft/blob/main/ft_putnbr_fd.c) - Affiche un entier dans un fichier donné.

### Fonctions de liste chaînée *(bonus)*
* [`ft_lstnew`](https://github.com/Jyzdcs/libft/blob/main/ft_lstnew_bonus.c) - Crée une nouvelle liste.
* [`ft_lstsize`](https://github.com/Jyzdcs/libft/blob/main/ft_lstsize_bonus.c) - Compte les éléments d'une liste.
* [`ft_lstlast`](https://github.com/Jyzdcs/libft/blob/main/ft_lstlast_bonus.c) - Trouve le dernier élément d'une liste.
* [`ft_lstadd_back`](https://github.com/Jyzdcs/libft/blob/main/ft_lstadd_back_bonus.c) - Ajoute un nouvel élément à la fin de la liste.
* [`ft_lstadd_front`](https://github.com/Jyzdcs/libft/blob/main/ft_lstadd_front_bonus.c) - Ajoute un nouvel élément au début de la liste.
* [`ft_lstdelone`](https://github.com/Jyzdcs/libft/blob/main/ft_lstdelone_bonus.c) - Supprime un élément de la liste.
* [`ft_lstclear`](https://github.com/Jyzdcs/libft/blob/main/ft_lstclear_bonus.c) - Supprime une séquence d'éléments d'une liste à partir d'un point de départ.
* [`ft_lstiter`](https://github.com/Jyzdcs/libft/blob/main/ft_lstiter_bonus.c) - Applique une fonction au contenu de tous les éléments d'une liste.
* [`ft_lstmap`](https://github.com/Jyzdcs/libft/blob/main/ft_lstmap_bonus.c) - Applique une fonction au contenu de tous
