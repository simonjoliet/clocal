#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <io.h>
#include <stdio.h>
#include <direct.h>

char FileInterface[_MAX_PATH+50];
char FileLocalisat[_MAX_PATH+50];
char FileExtension[_MAX_PATH+50];

char Val[ELEMENT_STRINGTABLE][ELEMENT_VALCARACTER];
int	 Idt[ELEMENT_STRINGTABLE];

char liste_csv[10][50];

static void _InitChaineCaractere(void);

BOOL _ChargeStructureLocalisation(void) { 
  errno_t OuvertureErreur;
  FILE * PointeurFichier = NULL;	
  char bufferA[ELEMENT_CLECARACTER+ELEMENT_VALCARACTER];
  char bufferB[ELEMENT_CLECARACTER+ELEMENT_VALCARACTER];

  char LocalisationFile[90]={0};

  int numLigne=0;
  int vli,vlj,vlk;

  sprintf(bufferA,".\\Lang\\");
  GetPrivateProfileString (TEXT("Localisation"), TEXT("File_Localisation"), TEXT("Lang_English"), bufferB, 90, TEXT(FileInterface));
  sprintf(LocalisationFile,"%s%s.csv",bufferA,bufferB);
  if((OuvertureErreur=fopen_s(&PointeurFichier, LocalisationFile,"r"))==0) {
	while (fgets(bufferA, ELEMENT_STRINGTABLE, PointeurFichier) != NULL {
		if(strlen(bufferA)>2) {	
			if((bufferA[0]=='1')||(bufferA[0]=='2')||(bufferA[0]=='3')||
			   (bufferA[0]=='4')||(bufferA[0]=='5')||(bufferA[0]=='6')||
			   (bufferA[0]=='7')||(bufferA[0]=='8')||(bufferA[0]=='9')) {

					Idt[numLigne] = atoi(strtok(bufferA,";"));
					strcpy(bufferB,strtok(NULL,";"));
					strcpy(Val[numLigne],strtok(NULL,";"));
					Val[numLigne][strlen(Val[numLigne])-1]='\0';
					//détection des caractères spéciaux
					for(vlj=0;vlj<=ELEMENT_VALCARACTER;vlj++) {	

						if(Val[numLigne][vlj]=='\\') {	// \n (retour ligne)

							if (Val[numLigne][vlj+1]=='n'){

								Val[numLigne][vlj]='\n';

								for(vlk=vlj+1;vlk<=ELEMENT_VALCARACTER-1;vlk++) {

									Val[numLigne][vlk]=Val[numLigne][vlk+1];
								}
							}
							// \t (tabulation)
							if (Val[numLigne][vlj+1]=='t') {

								Val[numLigne][vlj]='\t';
								for(vlk=vlj+1;vlk<=ELEMENT_VALCARACTER-1;vlk++) {
									Val[numLigne][vlk]=Val[numLigne][vlk+1];
								}
							}
						}
					}
			numLigne++;
			}
		}

		for(vli=0;vli<=ELEMENT_VALCARACTER;vli++) {
			bufferA[vli]=0;
		}

	}
	fclose(PointeurFichier);
  }
  else {		
  	  sprintf(bufferA,"Failed to open the localization profile. Please check if the file %s is still on the right location.",LocalisationFile);
		  
	  MessageBox(hWndPrinc_G,bufferA,"Localization error",MB_OK | MB_ICONERROR);
	  return FALSE;
  }
  return TRUE;
}

int LoadStringLocal(int inCle, char *outVal,int sizeOfBuffer) {
	int vli=0;
	int vlj=0;

	for(vli=0;vli<=ELEMENT_STRINGTABLE;vli++) {	
		if(inCle==Idt[vli]){
			strcpy(outVal,Val[vli]);
			Val[vli][sizeOfBuffer]='\0';
			return TRUE;
		}
	}

	return FALSE;
	{	strcpy(outVal,"\0");
		sprintf(outVal,"The element #%d isn't in the localization file. Abording.",inCle);
		MessageBox(hWndPrinc_G,outVal,"Missing a value", MB_OK | MB_ICONERROR);
		return FALSE;
	}

}

BOOL _ChargeTableauExtension(void) { 
	int vli, vlj;
	char outString[7];
	char vliBuffer[2];

	outString[0]='a';

	for(vli=0;vli<=3;vli++) {
		sprintf(vliBuffer,"%d",vli);
		
		GetPrivateProfileString(pszFamille_G, vliBuffer, "000000", outString, 7, FileExtension);
		for(vlj=0;vlj<=5;vlj++) {	
			if(outString[vlj]==49)
				extensionSta[vli][vlj]=TRUE;
			else
				extensionSta[vli][vlj]=FALSE;
		}
	}
	
	return FALSE;
}