      include \masm32\include\windows.inc
      include \masm32\include\masm32.inc
      include \masm32\include\gdi32.inc
      include \masm32\include\user32.inc
      include \masm32\include\kernel32.inc
      include \masm32\include\Comctl32.inc
      include \masm32\include\comdlg32.inc
      include \masm32\include\shell32.inc
      include \masm32\include\oleaut32.inc
      include \masm32\include\msvcrt.inc
      include \masm32\include\advapi32.inc
      include \masm32\macros\macros.asm

      includelib \masm32\lib\masm32.lib
      includelib \masm32\lib\gdi32.lib
      includelib \masm32\lib\user32.lib
      includelib \masm32\lib\kernel32.lib
      includelib \masm32\lib\Comctl32.lib
      includelib \masm32\lib\comdlg32.lib
       includelib \masm32\lib\advapi32.lib
     includelib \masm32\lib\shell32.lib
      includelib \masm32\lib\oleaut32.lib
      includelib \masm32\lib\msvcrt.lib

	include rsrc.inc

_DlgMainProc proto :dword,:dword,:dword,:dword
_NewListProc proto :dword,:dword,:dword,:dword
_NewEditProc proto :dword,:dword,:dword,:dword

_AddToList proto :dword
_SaveOrNot proto
_StringBrief proto :dword
_StringBack proto :dword
_SetText proto :dword
_ModifyOriText proto :dword,:dword
_memcpy proto
_UpdateWindow proto :dword
_GotoDlgProc proto :dword,:dword,:dword,:dword
_OptionDlgProc proto :dword,:dword,:dword,:dword
_DisplayMsg proto :dword
_ReplaceText proto 
_ReplaceDlgProc proto :dword,:dword,:dword,:dword
_RpcText proto :dword,:dword,:dword,:dword,:dword
_IsFormatted proto :dword
_StringToUnicode proto

_Encrypt proto :dword,:dword
_ExportTxt proto :dword,:dword
_ImportTxt proto :dword

_AddHandler proto :dword,:dword,:dword,:dword
_ProcHandler proto :dword,:dword,:dword,:dword

ID_TIMER equ 1

.data?
	hInstance dd ?
	hIcon dd ?
	hWinMain dd ?
	
	hRegKey dd ?
	
	hListO dd ?
	hListN dd ?
	hEditO dd ?
	hEditN dd ?
	hStatusLine dd ?
	hBtnModify dd ?
	hBtnSave dd ?
	hBtnGoto dd ?
	hBtnFind dd ?
	hBtnImp dd ?
	hBtnExp dd ?
;	hStatusByteO dd ?
;	hStatusByteN dd ?
	hBackBmp dd ?
	
	hBrushTr dd ?
	
	hFile dd ?
	hFile2 dd ?
	
	lpOldListProc dd ?
	lpOldEditProc dd ?
	
	lpFileBuff dd ?
	lpFileBuff2 dd ?
	
	lpTemp dd ?
	lpLineRecords2 dd ?
	lpBackBmp dd ?
	lpIndex dd ?
	lpIndex2 dd ?
	lpText2 dd ?
	
	szFileName db 512 dup(?)
	szStringO db 512 dup (?)
	szStringN db 512 dup (?)
	szTemp db 512 dup (?)
	szToFind db 64 dup (?)
	szToReplace db 64 dup (?)
	szReplaced db 32 dup (?)
	
	nTotalLine dd ?
	nRealLine dd ?
	nIndex dd ?
	nFileSizeNew dd ?
	
	bIsModified dd ?
	bScrolling dd ?
	bIsOpened dd ?
	
	dwTemp dd ?
	szNewName db 128 dup (?)
.data
	nVersion dd 1103
	nDword dd 4
	szRegKey db 'Software\AmaF\ME for Black',0
	szRegValueVersion db 'Version',0
	szNotNewest db '����ʹ�õı༭���������°汾��',0

	szDisplayName db '��ڵ��Ķ�ŵ˹ �ű��༭�� v1.1',0
	szGang db ' - ',0
	szTxt1 db 'txt',0
	szError db '����',0
	
	szCaptionFind db '�滻�ַ���',0
	szNewSc db 'NewSc\',0
	szSaveOrNot db '�ļ����޸ģ��Ƿ񱣴棿',0
	szFailOpen db '�޷����ļ���',0
	szFormat2 db '�ű��ļ�(*.gsc)',0,'*.gsc',0,'�����ļ�',0,'*.*',0,0
	szFormat3 db '�ı��ļ�(*.txt)',0,'*.txt',0,0
	szCountingLines db '���ڼ���������...',0
	szAddingString db '���ڻ�ȡ�ı�...',0
	szConvertingString db '����ת���ı�...',0
	szLineOver db '�������������',0
	szSaveSuccess db '�����ļ��ɹ���',0
	szSaveTxtSuccess db '����TXT�ɹ���',0
	szSaveTxtFail db '����TXTʧ�ܣ�',0
	szImpTxtSuccess db '����TXT�ɹ���',0
	szImpTxtFail db '����TXTʧ�ܣ���������������',0
	szTextNotFound db '�ַ���δ�ҵ���',0
	szRpcFormat db '�������%d���滻',0
	szNotTxt db '�ű���ʽ����ȷ����������',0
	szInstruction db '�س�',09h,09h,'���汾���޸�',0dh,0ah,
				'PageDown',09h,'��һ��(������)',0dh,0ah,
				'PageUp',09h,09h,'��һ��(������)',0dh,0ah,
				'Ctrl+S',09h,09h,'���������޸ĵ��ļ�',0dh,0ah,
				'Ctrl+G',09h,09h,'��ת��ĳ��',0dh,0ah,
				'Ctrl+F',09h,09h,'�滻�ı�',0dh,0ah,0