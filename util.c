#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern int RETOURNERfin;

int caractereActuel;
/*-------------------------------------------------------------------------*/

extern int nb_ligne;
int indent_xml = 0;
int indent_step = 1; // set to 0 for no indentation

/*-------------------------------------------------------------------------*/

void erreur(char *message) {
  fprintf (stderr, "Erreur a la ligne %d : ", nb_ligne);
  fprintf (stderr, "%s\n", message);
  if (stderr != NULL)
    {
        // Boucle de lecture des caractères un à un
        do
        {
            caractereActuel = fgetc(stderr); // On lit le caractère
            printf("\n\n%c", caractereActuel); // On l'affiche
        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de stderr)
        fclose(stderr);
    }
  RETOURNERfin = -1;
exit(1);
}

/*-------------------------------------------------------------------------*/

void erreur_1s(char *message, char *s) {
  fprintf( stderr, "Ligne %d : ", nb_ligne );
  fprintf( stderr, message, s );
  fprintf( stderr, "\n" );
  if (stderr != NULL)
    {
        // Boucle de lecture des caractères un à un
        do
        {
            caractereActuel = fgetc(stderr); // On lit le caractère
            printf("%c", caractereActuel); // On l'affiche
        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de stderr)
        fclose(stderr);
    }
  RETOURNERfin = -1;
exit(1);
}

/*-------------------------------------------------------------------------*/

void erreur_1s_tab_decm( char *nom , char* message) {
  fprintf( stderr, "Erreur : ");
  fprintf( stderr, "semantique : %s - %s.", nom, message );
  fprintf( stderr, "\n" );
  if (stderr != NULL)
    {
        // Boucle de lecture des caractères un à un
        do
        {
            caractereActuel = fgetc(stderr); // On lit le caractère
            printf("%c", caractereActuel); // On l'affiche
        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de stderr)
        fclose(stderr);
    }
  RETOURNERfin = -1;
exit(1);
}

/*-------------------------------------------------------------------------*/

void erreur_1d(const char *message, int uc) {
  char *s= malloc(4*sizeof(char));
  sprintf(s, "%d", uc);
  fprintf( stderr, "Ligne %d : ", nb_ligne );
  fprintf( stderr, message, s );
  fprintf( stderr, "\n" );
  RETOURNERfin = -1;
exit(1);
}
/*-------------------------------------------------------------------------*/

void erreur_1d_synt(const char *message, int uc) {
  char *s= malloc(4*sizeof(char));
  sprintf(s, "%d", uc);
  fprintf( stderr, "Ligne %d : ", nb_ligne );
  fprintf( stderr, "syntaxique --> " );
  fprintf( stderr, message, s );
  fprintf( stderr, "\n" );
  if (stderr != NULL)
    {
        // Boucle de lecture des caractères un à un
        do
        {
            caractereActuel = fgetc(stderr); // On lit le caractère
            printf("%c", caractereActuel); // On l'affiche
        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de stderr)
        fclose(stderr);
    }
  RETOURNERfin = -1;
exit(1);
}
/*-------------------------------------------------------------------------*/

void erreur_1d_tab_dec(const char *message, int uc) {
  char *s= malloc(4*sizeof(char));
  sprintf(s, "%d", uc);
  fprintf( stderr, "Ligne %d : ", nb_ligne );
  fprintf( stderr, "semantique --> " );
  fprintf( stderr, message, s );
  fprintf( stderr, "\n" );
  if (stderr != NULL)
    {
        // Boucle de lecture des caractères un à un
        do
        {
            caractereActuel = fgetc(stderr); // On lit le caractère
            printf("%c", caractereActuel); // On l'affiche
        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de stderr)
        fclose(stderr);
    }
  RETOURNERfin = -1;
exit(1);
}

/*-------------------------------------------------------------------------*/

void erreur_1d_abstrait(const char *message, int uc) {
  char *s= malloc(4*sizeof(char));
  sprintf(s, "%d", uc);
  fprintf( stderr, "Ligne %d : ", nb_ligne );
  fprintf( stderr, "abstrait --> " );
  fprintf( stderr, message, s );
  fprintf( stderr, "\n" );
  if (stderr != NULL)
    {
        // Boucle de lecture des caractères un à un
        do
        {
            caractereActuel = fgetc(stderr); // On lit le caractère
            printf("%c", caractereActuel); // On l'affiche
        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de stderr)
        fclose(stderr);
    }
  RETOURNERfin = -1;
exit(1);
}

/*-------------------------------------------------------------------------*/

char *duplique_chaine(char *src) {
  char *dest = malloc(sizeof(char) * strlen(src));
  strcpy(dest, src);
  return dest;
}

/*-------------------------------------------------------------------------*/

void indent() {
    int i;
    for( i = 0; i < indent_xml; i++ ) {
      printf( "  " );
    }    
}
/*-------------------------------------------------------------------------*/
void affiche_balise_ouvrante(const char *fct_, int trace_xml) {
  if( trace_xml ) {
    indent();
    indent_xml += indent_step ;
	  fprintf (stdout, "<%s>\n", fct_);
	}  
}

/*-------------------------------------------------------------------------*/

void affiche_balise_fermante(const char *fct_, int trace_xml) {
  if(trace_xml) {
    indent_xml -= indent_step ;
    indent();
    fprintf (stdout, "</%s>\n", fct_);
  }
}

/*-------------------------------------------------------------------------*/

void affiche_texte(char *texte_, int trace_xml) {
  if(trace_xml) {
    indent();
    fprintf (stdout, "%s\n", texte_);
  }
}

/*-------------------------------------------------------------------------*/

void affiche_xml_texte( char *texte_ ) {
  int i = 0;
  while( texte_[ i ] != '\0' ) {
    if( texte_[ i ] == '<' ) {
      fprintf( stdout, "&lt;" );
    }
    else if( texte_[ i ] == '>' ) {
      fprintf( stdout, "&gt;" );
    }
    else if( texte_[ i ] == '&' ) {
      fprintf( stdout, "&amp;" );
    }
    else {
      putchar( texte_[i] );
    }
    i++;
  }
}

/*-------------------------------------------------------------------------*/

void affiche_element(char *fct_, char *texte_, int trace_xml) {
  if(trace_xml) {
    indent();
    fprintf (stdout, "<%s>", fct_ );
    affiche_xml_texte( texte_ );
    fprintf (stdout, "</%s>\n", fct_ );
  }
}