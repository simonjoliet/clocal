#ifdef __cplusplus
extern "C"
{
#endif

extern int LoadStringLocal(int inCle, char *outVal,int sizeOfBuffer);

extern BOOL _ChargeStructureLocalisation(void);
extern BOOL _ChargeTableauExtension(void);

extern char FileInterface[_MAX_PATH+50];
extern char FileLocalisat[_MAX_PATH+50];
extern char FileExtension[_MAX_PATH+50];

extern char Val[ELEMENT_STRINGTABLE][ELEMENT_VALCARACTER];
extern int  Idt[ELEMENT_STRINGTABLE];

extern char liste_csv[10][50];		// on gère au maxi 10 fichiers csv dans le rép. Lang

extern BOOL extensionSta[4][6];