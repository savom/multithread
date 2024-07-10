À©µµ¿ì´Â µÎ °¡Áö ÇüÅÂÀÇ ¾ÖÇÃ¸®ÄÉÀÌ¼ÇÀ» Áö¿øÇÏ´Âµ¥,
-±×·¡ÇÈ À¯Àú ÀÎÅÍÆäÀÌ½º(GUI)
- ÄÜ¼Ö À¯Àú ÀÎÅÍÆäÀÌ½º(CUI)
gui ±â¹ÝÀÇ ¾ÖÇÃ¸®ÄÉÀÌ¼ÇÀº »ç¿ëÀÚ¿ÍÀÇ »óÈ£ÀÛ¿ëÀ» ¼öÇàÇÏ±âµµ ÇÑ´Ù.
cui ±â¹ÝÀÇ ¾ÖÇÃ¸®ÄÉÀÌ¼ÇÀº ÅØ½ºÆ®¸¦ ±â¹ÝÀ¸·Î ÇÑ´Ù.

µÎ °¡Áö ÇüÅÂÀÇ ¾ÖÇÃ¸®ÄÉÀÌ¼ÇÀº °æ°è°¡ ¸íÈ®ÇÏÁö ¾Ê´Ù.

»ç¿ëÀÚ°¡ ¾ÖÇÃ¸®ÄÉÀÌ¼ÇÀ» ¼öÇàÇÏ¸é ¿î¿µÃ¼Á¦ÀÇ ·Î´õ(loader)´Â ½ÇÇà ÆÄÀÏÀÇ Çì´õ¸¦ È®ÀÎÇÏ¿© ¼­ºê½Ã½ºÅÛ °ªÀ» °¡Á®¿Â´Ù.

À©µµ¿ì ¾ÖÇÃ¸®ÄÉÀÌ¼ÇÀº ¾ÖÇÃ¸®ÄÉÀÌ¼ÇÀÌ ¼öÇàÀ» ½ÃÀÛÇÒ ÁøÀÔÁ¡ ÇÔ¼ö¸¦ ¹Ýµå½Ã °¡Á®¾ß ÇÑ´Ù.µÎ °¡Áö ÇüÅÂÀÇ ÁøÀÔÁ¡ ÇÔ¼ö¸¦ »ç¿ëÇÒ ¼ö ÀÖ´Ù.
	int WINAPI _tWinMain(
		HINSTANCE hInstanceExe,
		HINSTANCE,
		PTSTR pszCmdLine,
		int nCmdShow);

	int _tmain(
		int argc,
		TCHAR* argv[],
		TCHAR* envp[]);

ÁøÀÔÁ¡ ÇÔ¼ö¸¦ »ç¿ëÇÒÁö´Â À¯´ÏÄÚµå ¹®ÀÚ¿­ÀÇ »ç¿ë ¿©ºÎ¿¡ ´Þ·ÁÀÖ´Ù
¿î¿µÃ¼Á¦´Â ¿ì¸®°¡ ÀÛ¼ºÇÑ ÁøÀÔÁ¡ ÇÔ¼ö¸¦ Á÷Á¢ È£ÃâÇÏÁö ¾ÊÀ¸¸ç, C/C++ ·±Å¸ÀÓ¿¡ ÀÇÇØ ±¸ÇöµÈ C/C++ ·±Å¸ÀÓ ½ÃÀÛÇÔ¼ö(C / C++ runtime startup function)¸¦ È£ÃâÇÑ´Ù.
ÀÌ·¯ÇÑ ÇÔ¼ö´Â ¸µÅ© ½Ã -entry: ¸í·ÉÇà ¿É¼Ç(command-line option)À» ÅëÇØ ¼³Á¤µÈ´Ù.
C / C++ ·±Å¸ÀÓ ½ÃÀÛ ÇÔ¼ö´Â mallocÀÌ³ª free¿Í °°Àº ÇÔ¼ö°¡ È£ÃâµÉ ¼ö ÀÖµµ·Ï C / C++·±Å¸ÀÓ ¶óÀÌºê·¯¸®¿¡ ´ëÇÑ ÃÊ±âÈ­¸¦ ¼öÇàÇÑ´Ù.
¶ÇÇÑ, °³¹ßÀÚ°¡ ÄÚµå »ó¿¡¼­ ¼±·±ÇÑ °¢Á¾ Àü¿ª ¿ÀºêÁ§Æ®³ª staticÀ¸·Î ¼±¾ðµÈ C++¿ÀºêÁ§Æ®µéÀ» ÄÚµå°¡ ¼öÇàµÇ±â Àü¿¡ ÀûÀýÈ÷ »ý¼ºÇÏ´Â ¿ªÈ°À» ¼öÇàÇÑ´Ù.

¸µÄ¿´Â ½ÇÇà ÆÄÀÏÀ» ¸µÅ©ÇÏ´Â ´Ü°è¿¡¼­ ÀûÀýÇÑ C / C++·±Å¸ÀÓ ½ÃÀÛÇÔ¼ö¸¦ ¼±ÅÃÇØ¾ß ÇÑ´Ù.
/SUBSYSTEM:WINDOWS ¸µÄ¿ ½ºÀ§Ä¡°¡ ¼³Á¤µÇ¾î ÀÖÀ¸¸é ¸µÄ¿´Â WinMainÀÌ³ª wWinMainÇÔ¼ö¸¦ Ã£°ÔµÇ¸ç, ÀÌ·¯ÇÑ ÇÔ¼ö°¡ Á¸ÀçÇÏÁö ¾ÊÀ» °æ¿ì "unresolved external symbol"¿¡·¯¸¦ ¹ÝÈ¯ÇÑ´Ù.
ÇÔ¼ö¸¦ Á¤»óÀûÀ¸·Î Ã£À» ¼ö ÀÖ´Ù¸é WInMainCRTStartupÀÌ³ª wWinMainCRTStartup ÇÔ¼ö¸¦ È£ÃâÇÏµµ·Ï ¼³Á¤ÇÑ´Ù.

¹Ý¸é, /SUBSYSTEM:CONSOLE ¸µÄ¿ ½ºÀ§Ä¡°¡ ÁöÁ¤µÇ¸é ¸µÄ¿´Â mainÀÌ³ª wmain ÇÔ¼ö¸¦ Ã£°í, mainCRTStartupÀÌ³ª wmainCRTStartup ÇÔ¼ö¸¦ È£ÃâÇÏµµ·Ï ¼³Á¤ÇÑ´Ù.

ÇÁ·ÎÁ§Æ® ¼³Á¤¿¡¼­ /SUBSYSTEM ¸µÄ¿ ½ºÀ§Ä¡¸¦ ¿ÏÀüÈ÷ Á¦°ÅÇÒ ¼öµµ ÀÖ´Ù´Â °ÍÀº Àß ¾Ë·ÁÁöÀÖÁö ¾Ê´Ù.
ÀÌ·¯ÇÑ ¸µÄ¿ ½ºÀ§Ä¡¸¦ Á¦°ÅÇÏ°Ô µÇ¸é ¸µÄ¿´Â ÀÚµ¿ÀûÀ¸·Î ¾ÖÇÃ¸®ÄÉÀÌ¼Ç¿¡ ÀûÇÕÇÑ ¼³Á¤ °ªÀ» Ã£¾Æ³½´Ù.
¸µÄ¿ ´Ü°è¿¡¼­ ¸µÄ¿´Â ÄÚµå¿¡¼­ 4°³ÀÇ ÇÔ¼ö Áß(WinMain, wWinMain, main, wmain) ¾î¶² °ÍÀÌ ±¸ÇöµÇ¾ú´ÂÁö¸¦ È®ÀÎÇÏ°í ÀûÀýÇÑ ¼­ºê½Ã½ºÅÛ ¼³Á¤¸¦ ÃßÁ¤ÇÑ´Ù.

¸ðµç C/C++ ·±Å¸ÀÓ ½ÃÀÛ ÇÔ¼ö´Â ±âº»ÀûÀ¸·Î µ¿ÀÏÇÑ ÀÛ¾÷À» ¼öÇàÇÑ´Ù.
Â÷ÀÌÁ¡ÀÌ¶ó¸é C·±Å¸ÀÓ ¶óÀÌºê·¯¸®ÀÇ ÃÊ±âÈ­ ÀÌÈÄ¿¡ ¼öÇàÇØ¾ß ÇÒ ÁøÀÔÁ¡ ÇÔ¼ö°¡ ¾î¶² °ÍÀÌ³Ä¿¡ µû¶ó ANSI¹®ÀÚ¿­ÀÌ³ª À¯´ÏÄÚµå ¹®ÀÚ¿­À» Ã³¸®ÇØ¾ß ÇÑ´Ù´Â Á¡ÀÌ´Ù.

	- »õ·Î¿î ÇÁ·Î¼¼½ºÀÇ ÀüÃ¼ ¸í·ÉÇàÀ» °¡¸®Å°´Â Æ÷ÀÎÅÍ¸¦ È¹µæÇÑ´Ù.
	- »õ·Î¿î ÇÁ·Î¼¼½ºÀÇ È¯°æº¯¼ö¸¦ °¡¸®Å°´Â Æ÷ÀÎÅÍ¸¦ È¹µæÇÑ´Ù.
	- C / C++ ·±Å¸ÀÓ ¶óÀÌºê·¯¸®ÀÇ Àü¿ªº¯¼ö¸¦ ÃÊ±âÈ­ÇÑ´Ù. »ç¿ëÀÚ ÄÚµå°¡ Stdlib.hÆÄÀÏÀ» Æ÷ÇÔÇÏ¸é ÀÌ º¯¼ö¿¡ Á¢±ÙÇÒ ¼ö ÀÖ´Ù.
	- C / C++ ·±Å¸ÀÓ ¶óÀÌºê·¯¸®ÀÇ ¸Þ¸ð¸® ÇÒ´ç ÇÔ¼ö(malloc°ú colloc)¿Í Àú¼öÁØ ÀÔÃâ·Â ·çÆ¾ÀÌ »ç¿ëÇÏ´Â ÈüÀ» ÃÊ±âÈ­ÇÑ´Ù.
	- ¸ðµç Àü¿ª ¿ÀºêÁ§Æ®¿Í static C++ Å¬·¡½º ¿ÀºêÁ§Æ®ÀÇ »ý¼ºÀÚ¸¦ È£ÃâÇÑ´Ù.

ÀÌ·¯ÇÑ ÃÊ±âÈ­ °úÁ¤ÀÌ ¸ðµå ¿Ï·áµÇ°í ³ª¼­¾ß C / C++ ½ÃÀÛ ÇÔ¼ö´Â ºñ·Î¼Ò ¾ÖÇÃ¸®ÄÉÀÌ¼ÇÀÇ ÁøÀÔÁ¡ ÇÔ¼ö¸¦ È£ÃâÇÑ´Ù.

¸¸ÀÏ _tWinMainÇÔ¼ö¸¦ ±¸ÇöÇÏ¿´°í _UNICODE°¡ Á¤ÀÇµÇ¾î ÀÖ´Ù¸é ´ÙÀ½°ú °°Àº ÄÚµå°¡ ¼öÇàµÉ °ÍÀÌ´Ù.
	
	GetStartupInfo(&StartupInfo);
	int nMainRetval = wWinMain((HINSTANCE)&__ImageBase, nullptr, pszCommandLineUnicode, (StartupInfo.dwFlags & STARTF_USESHOWWINDOW) ? StartupInfo.wShowWindow : SW_SHOWDEFAULT);

_UNICODE°¡ Á¤ÀÇµÇ¾î ÀÖÁö ¾Ê´Ù¸é
	
	GetStartupInfo(&StartupInfo);
	int nMainRetval = WinMain((HINSTANCE)&__ImageBase, nullptr, pszCommandLineAnsi, (StartupInfo.dwFlags & STARTF_USESHOWWINDOW) ? StartupInfo.wShowWindow : SW_SHOWDEFAULT);

__ImageBase´Â ¸µÄ¿°¡ Á¤ÀÇÇÏ´Â °¡»óÀÇ º¯¼ö·Î¼­ ¸Þ¸ð¸®ÀÇ ¾î´À À§Ä¡¿¡ ½ÇÇÛ ÆÄÀÏÀ» ·ÎµåÇÏ¿´´ÂÁö¸¦ ¾Ë·ÁÁÖ´Â °ªÀ¸·Î ¼³Á¤µÈ´Ù.

¸¸ÀÏ _tmain ÇÔ¼ö¸¦ ±¸ÇöÇÏ¿´°í _UNICODE°¡ Á¤ÀÇµÇ¾î ÀÖ´Ù¸é
	
	int nMainRetVal = wmain(argc, argv envp);

_UNICODE°¡ Á¤ÀÇµÇ¾î ÀÖÁö ¾Ê´Ù¸é

	int nMainRetVal = _tmain(argc, argv, envp);

visual studioÀÇ À§Àúµå¸¦ ÅëÇØ ¾ÖÇÃ¸®ÄÉÀÌ¼ÇÀ» »ý¼ºÇÏ°Ô µÇ¸é ´ÙÀ½ÀÇ ¿¹¿Í °°ÀÌ CUI ¾ÖÇÃ¸®ÄÉÀÌ¼ÇÀÇ ÁøÀÔÁ¡ ÇÔ¼ö¿¡¼­ 3¹øÂ° ¸Å°³º¯¼ö´Â Æ÷ÇÔµÇÁö ¾ÊÀ» °ÍÀÌ´Ù.

	int _tmain(int argc, TCHAR* argv[]);

¸¸ÀÏ ÇÁ·Î¼¼½ºÀÇ È¯°æº¯¼ö¿¡ Á¢±ÙÇÒ ÇÊ¿ä°¡ ÀÖ´Ù¸é ¾ÕÀÇ Á¤ÀÇ¸¦ ´ÙÀ½°ú °°ÀÌ º¯°æÇØ¾ßÇÑ´Ù.

	int _tmain(int argc, TCHAR* argv[], TCHAR* env[]);

env ¸Å°³º¯¼ö´Â 'È¯°æº¯¼ö ÀÌ¸§ = °ª'ÀÇ ÇüÅÂ·Î ¸ðµç È¯°æº¯¼ö¸¦ Æ÷ÇÔÇÏ´Â ¹è¿­À» °¡¸®Å°°í ÀÖ´Ù.

ÁøÀÔÁ¡ ÇÔ¼ö°¡ ¹ÝÈ¯µÇ¸é ½ÃÀÛ ÇÔ¼ö´Â ÁøÀÔÁ¡ ÇÔ¼öÀÇ ¹ÝÈ¯ °ªÀ» ÀÎÀÚ·Î ÇÏ¿© C / C++ ·±Å¸ÀÓ ¶óÀÌºê·¯¸®ÀÇ exitÇÔ¼ö¸¦ È£ÃâÇÑ´Ù. exitÇÔ¼ö´Â ´ÙÀ½°ú °°Àº ÀÛ¾÷À» ¼öÇàÇÑ´Ù.

	- _onexitÇÔ¼ö¸¦ ÀÌ¿ëÇÏ¿© µî·ÏÇØ µÎ¾ú´ø ÇÔ¼ö¸¦ È£ÃâÇÑ´Ù.
	- ¸ðµç Àü¿ª Å¬·¡½º ¿ÀºêÁ§Æ®¿Í static C++Å¬·¡½º ¿ÀºêÁ§Æ® ÆÄ±«ÀÚ¸¦ È£ÃâÇÑ´Ù.
	- DEBUGºôµåÀÇ °æ¿ì _CRTDBG_LEAK_CHECK_DF ÇÃ·¡±×°¡ ¼³Á¤µÇ¾î ÀÖÀ¸¸é C / C++ ·±Å¸ÀÓ ¸Þ¸ð¸®¿¡¼­ ¸Þ¸ð¸® ´©¼ö »óÈ²À» _CrtDumpMemoryleaks ÇÔ¼ö¸¦ È£ÃâÇÏ¿© ³ª¿­ÇØ ÁØ´Ù.
	- nMainRetval °ªÀ» ÀÎÀÚ·Î ÇÏ¿© ExitProcess ÇÔ¼ö¸¦ È£ÃâÇÑ´Ù. ÀÌ ÇÔ¼ö¸¦ È£ÃâÇÏ¸é ¿î¿µÃ¼Á¦´Â ÇÁ·Î¼¼½º¸¦ Á¾·áÇÏ°í ÇÁ·Î¼¼½ºÀÇ Á¾·á ÄÚµå¸¦ ¼³Á¤ÇÑ´Ù.


	1. ÇÁ·Î¼¼½º ÀÎ½ºÅÏ½º ÇÚµé
		¸ðµç ½ÇÇà ÆÄÀÏ°ú DLLÆÄÀÏÀº ÇÁ·Î¼¼½ºÀÇ ¸Þ¸ð¸® °ø°£ »ó¿¡ ·ÎµåµÉ ¶§ °íÀ¯ÀÇ ÀÎ½ºÅÏ½º ÇÚµéÀ» ÇÒ´ç¹Þ´Â´Ù.
		ÀÌ·¯ÇÑ ÀÎ½ºÅÏ½º ÇÚµéÀº (w)WinMainÀÇ Ã¹ ¹øÂ° ¸Å°³º¯¼öÀÎ hInstanceExe¸¦ ÅëÇØ Àü´ÞµÈ´Ù.
		ÀÌ ÇÚµé °ªÀº º¸Åë ¸®¼Ò½º¸¦ ·ÎµåÇÒ ¶§ »ç¿ëµÈ´Ù.

		HICON LoadIcon(
			HINSTANCE hInstance,
			PCTSTR pszIcon);
		
		loadIconÀÇ Ã¹ ¹ø¤Š ¸Å°³º¯¼ö·Î´Â ¸®¼Ò½º°¡ Æ÷ÇÔµÇ¾î ÀÖ´Â ÆÄÀÏÀÇ ÀÎ½ºÅÏ½º ÇÚµéÀ» ÁöÁ¤ÇÏ¸é µÈ´Ù.
		¸¹Àº ¾ÖÇÃ¸®ÄÉÀÌ¼Ç¿¡¼­ (w)WinMainÀÇ hInstanceExe ¸Å°³º¯¼ö¸¦ Àü¿ªº¯¼ö¿¡ ÀúÀåÇØ µÎ¾î ½ÇÇà ÆÄÀÏÀÇ ÀüÃ¼ ¼Ò½º¿¡¼­ ÀÌ °ªÀ» ¼Õ½±°Ô Á¢±ÙÇÒ ¼ö ÀÖµµ·Ï ÇÏ°ï ÇÑ´Ù.

		hInstanceExe ¸Å°³º¯¼öÀÇ ½ÇÁ¦ °ªÀº ½Ã½ºÅÛÀÌ ÇÁ·Î¼¼½ºÀÇ ¸Þ¸ð¸® ÁÖ¼Ò °ø°£ »ó¿¡ ½ÇÇà ÆÄÀÏÀ» ·ÎµåÇÒ ½ÃÀÛ ¸Þ¸ð¸® ÁÖ¼Ò(base memory address)´Ù.
		½ÇÇà ÆÄÀÏÀÌ ·ÎµåµÉ ½ÃÀÛ ÁÖ¼Ò´Â ¸µÄ¿¿¡ ÀÇÇØ °áÁ¤µÈ´Ù.
		¼­·Î ´Ù¸¥ ¸µÄ¿´Â ¼­·Î ´Ù¸¥ ±âº» ½ÃÀÛ ÁÖ¼Ò¸¦ °¡Áú ¼ö ÀÖ´Ù.

		GetModuleHandle ÇÔ¼ö´Â ½ÇÇà ÆÄÀÏÀÌ³ª DLLÆÄÀÏÀÌ ÇÁ·Î¼¼½ºÀÇ ¸Þ¸ð¸® °ø°£ »óÀÇ ¾îµð¿¡ ·ÎµåµÇ¾î ÀÖ´ÂÁö¸¦ °¡¸®Å°´Â ÇÚµé/½ÃÀÛ ÁÖ¼Ò¸¦ ¹ÝÈ¯ÇÑ´Ù.
			
			HMODULE GetModuleHandle (PCTSTR pszMoudule);

		ÀÌ ÇÔ¼ö¸¦ È£ÃâÇÒ ¶§¿¡´Â È£ÃâÇÏ´Â ÇÁ·Î¼¼½ºÀÇ ÁÖ¼Ò °ø°£¿¡ ·ÎµåµÇ¾î ÀÖ´Â ½ÇÇà ÆÄÀÏ¸íÀÌ³ª DLLÆÄÀÏÀ» '\0'À¸·Î ³¡³ª´Â ¹®ÀÚ¿­·Î Àü´ÞÇÏ¸é µÈ´Ù.
		½Ã½ºÅÛÀÌ ÁöÁ¤ÇÑ ½ÇÇà ÆÄÀÏÀÌ³ª DLLÆÄÀÏÀ» Ã£¾Æ³»¸é GetModuleHandle ÇÔ¼ö´Â ÆÄÀÏÀÌ ·ÎµåµÈ ½ÃÀÛÁÖ¼Ò¸¦ ¹ÝÈ¯ÇÑ´Ù.
		¹Ý¸é, ½Ã½ºÅÛÀÌ ÇØ´ç ÆÄÀÏÀ» Ã£À» ¼ö ¾ø´Ù¸é NULLÀ» ¹ÝÈ¯ÇÑ´Ù.
		GetModuleHandleÀ» È£ÃâÇÒ ¶§ pszModule ¸Å°³º¯¼ö·Î NULL°ªÀ» Àü´ÞÇÒ ¼öµµ ÀÖ´Âµ¥, ÀÌ °æ¿ì GetModuleHandleÀº ÁhÀç ¼öÇà ÁßÀÎ ½ÇÇà ÆÄÀÏÀÌ ·ÎµåµÈ ½ÃÀÛ ÁÖ¼Ò¸¦ ¹ÝÈ¯ÇÑ´Ù.

		ÀÌ ÇÔ¼ö°¡ DLL ³»¿¡¼­ È£ÃâµÈ´Ù¸é ¾î¶² ¸ðµâ¿¡ Æ÷ÇÔµÈµð¾î ÄÚµå°¡ ¼öÇà ÁßÀÎÁö ¾Ë¾Æ³»±â À§ÇÑ µÎ °¡Áö ¹æ¹ýÀÌ ÀÖ´Ù.
			1. ¸µÄ¿¿¡ ÀÇÇØ Á¤ÀÇµÇ´Â °¡»óº¯¼öÀÎ __ImageBase°¡ ÇöÀç ¼öÇà ÁßÀÎ ¸ðµâÀÇ ½ÃÀÛ ÁÖ¼Ò¸¦ °¡¸®Å°°í ÀÖ´Ù´Â »ç½ÇÀ» È°¿ëÇÒ ¼ö ÀÖ´Ù.
			2. Ã¹ ¹ø¤Š ¸Å°³º¯¼ö·Î GET_MODULE_HANDLE_EX_FALG_FROM_ADDRESS¸¦ µÎ ¹ø¤Š ¸Å°³º¯¼ö·Î ÇöÀç ¼öÇà ÁßÀÎ ÇÔ¼öÀÇ ÁÖ¼Ò¸¦ ÁöÁ¤ÇÏ¿© GetModuleHandleEx ÇÔ¼ö¸¦ È£ÃâÇÏ´Â °ÍÀÌ´Ù.
			   ¸¶Áö¸· ¸Å°³º¯¼ö·Î Àü´Þµµ´Â °ªÀº HMODULEÀ» °¡¸®Å°´Â Æ÷ÀÎÅÍ °ªÀÎµ¥, µÎ ¹ø¤Š ¸Å°³º¯¼ö·Î Àü´ÞÇÑ ÇÔ¼ö¸¦ Æ÷ÇÔÇÏ°í ÀÖ´Â DLLÀÇ ½ÃÀÛ ÁÖ¼Ò¸¦ ¹ÝÈ¯ÇØ ÁØ´Ù.

		GetModuleHandle ÇÔ¼öÀÇ Áß¿äÇÑ µÎ °¡Áö Æ¯¼ºÀ» ±â¾ïÇØ¾ß ÇÑ´Ù.
			1. ÀÌ ÇÔ¼ö´Â ÀÚ½ÅÀ» È£ÃâÇÑ ÇÁ·Î¼¼½ºÀÇ ÁÖ¼Ò °ø°£¸¸À» È®ÀÎÇÑ´Ù´Â °ÍÀÌ´Ù.
				¸¸ÀÏ ÀÌ ÇÔ¼ö¸¦ È£ÃâÇÏ´Â ÇÁ·Î¼¼½º°¡ ¾î¶°ÇÑ °ø¿ë ´ÙÀÌ¾ó·Î±× ÇÔ¼öµµ »ç¿ëÇÏÁö ¾Ê´Â °æ¿ì NULLÀ» ¹ÝÈ¯ÇÏ°Ô µÉ °ÍÀÌ´Ù.
			2. GetModuleHandleÀ» È£ÃâÇÒ ¶§ NULL°ªÀ» Àü´ÞÇÏ°Ô µÇ¸é ÇÁ·Î¼¼½º ÁÖ¼Ò °ø°£¿¡ ·ÎµåµÈ ½ÇÇà ÆÄÀÏÀÇ ½ÃÀÛ ÁÖ¼Ò¸¦ ¹ÝÈ¯ÇÑ´Ù´Â°ÍÀÌ´Ù.
				DLLÆÄÀÏÀÇ ½ÃÀÛ ÁÖ¼Ò°¡ ¾Æ´Ï¶ó ½ÇÇà ÆÄÀÏ¤©ÀÇ ½ÃÀÛ ÁÖ¼Ò¸¦ ¹ÝÈ¯ÇÑ´Ù.

			1. ÇÁ·Î¼¼½ºÀÇ ÀÌÀü ÀÎ½ºÅÏ½º ÇÚµé
				C / C++ ·±Å¸ÀÓ ½ÃÀÛÄÚµå´Â Ç×»ó (w)WinMainÀÇ hPrevInstance ¸Å°³º¯¼ö·Î NULLÀ» Àü´ÞÇÑ´Ù.
				µÎ ¹øÂ° ¸Å°³º¯¼ö¿¡ ÀÌ¸§ÀÌ ¾ø±â ¶§¹®¿¡, ÄÄÆÄÀÏ·¯´Â "¸Å°³º¯¼ö°¡ ÂüÁ¶µÇÁö ¾Ê¾Ò´Ù."´Â °æ°í´Â ¹ß»ý½ÃÅ°Áö ¾Ê´Â´Ù.

			2. ÇÁ·Î¼¼½ºÀÇ ¸í·ÉÇà
				»õ·Î¿î ÇÁ·Î¼¼½º°¡ »ý¼ºµÇ¸é ÇÁ·Î¼¼½º¿¡ ¸í·ÉÇàÀÌ Àü´ÞµÈ´Ù.
				¸í·ÉÇà(command Line)Àº ºñ¾î ÀÖ´Â °æ¿ì°¡ °ÅÀÇ ¾ø´Ù.
				»õ·Î¿î ÇÁ·Î¼¼½º¸¦ »ý¼ºÇÏ±â À§ÇØ¼­´Â ¸í·ÉÇàÀÌ Ã¹ ¹øÂ° ÅäÅ«À¸·Î ½ÇÇà ÆÄÀÏÀÇ ÀÌ¸§À» Àü´ÞÇÒ °ÍÀÌ±â ¶§¹®ÀÌ´Ù.

				¾ÖÇÃ¸®ÄÉÀÌ¼ÇÀº ¸í·ÉÇàÀ¸·Î Àü´ÞµÈ ¹®ÀÚ¿­À» ´Ù¾çÇÑ ¹æ¹ýÀ¸·¯ ±¸ºÐ Áþ°í, °¢°¡¿¡ ÀÇ¹Ì¸¦ ºÎ¿©ÇÒ ¼ö ÀÖ´Ù.
				
				GetCommandLineÇÔ¼ö¸¦ È£­„ÇÏ¿© ÇÁ·Î¼¼½ºÀÇ ¸í·ÉÇà ÀüÃ¼¸¦ °¡¸®Å°´Â Æ÷ÀÎÅÍ¸¦ È¹µæÇÒ ¼ö ÀÖ´Ù.

					PTSTR GetCommandLine();
			
				ÀÌ ÇÔ¼ö´Â ½ÇÇà ÆÄÀÏÀÇ ÀüÃ¼ °æ·Î¸íÀ» Æ÷ÇÔÇÏ´Â ÀüÃ¼ ¸í·ÉÇàÀÇ ³»¿ëÀ» ´ã°í ÀÖ´Â ¹öÆÛ¸¦ °¡¸®Å°´Â Æ÷ÀÎÅÍ¸¦ ¹ÝÈ¯ÇÑ´Ù.
				GetCommandLine ÇÔ¼ö´Â ¿©·¯¹ø È£ÃâÇÏ´õ¶óµµ Ç×»ó µ¿ÀÏÇÑ ¹öÆÛÀÇ ÁÖ¼Ò¸¦ ¹ÝÈ¯ÇÑ´Ù´Â »ç½ÇÀ» ¾Ë¾ÆµÎÀÚ.

				¸¹Àº ¾ÖÇÃ¸®ÄÉÀÌ¼ÇµéÀÌ ¸í·ÉÇàÀ¸·Î Àü´ÞµÈ ³»¿ëÀ» ÅäÅ«À¸·Î ±¸ºÐÇÏ¿© »ç¿ëÇÏ´Â °ÍÀ» ¼±È£ÇÑ´Ù.
				¾ÖÇÃ¸®ÄÉÀÌ¼ÇÀº ÀÌ·¸°Ô °¢±â ±¸ºÐµÈ ÅäÅ«¿¡ Á¢±ÙÇÏ±â À§ÇØ Àü¿ª __argc¿Í __argv(È¤Àº __wargv)º¯¼öµéÀ» »ç¿ëÇÒ ¼ö ÀÖ´Ù.
					
					PWSTR* CommandLineToArgvW(
						PWSTR pszCmdLine,
						int* pNumArgs);

				Ã¹ ¹ø¤Š ¸Å°³º¯¼öÀÎ pszCmdLineÀ¸·Î´Â ¸í·ÉÇà ¹®ÀÚ¿­À» °¡¸®Å°´Â Æ÷ÀÎÅÍ¸¦ Àü´ÞÇÏ¸é µÈ´Ù.
				pNumArgs ¸Å°³º¯¼ö·Î´Â Á¤¼ö¸¦ °¡¸®Å°´Â Æ÷ÀÎÅÍ¸¦ Àü´ÞÇÏ¸é µÇ°í, ¸í·ÉÇà¿¡ Æ÷ÇÔµÈ ÀÎÀÚÀÇ °³¼ö°¡ ¹ÝÈ¯µÈ´Ù.
				CommandLineToArgvw´Â ¹ÝÈ¯ °ªÀ¸·Î À¯´ÏÄÚµå ¹®ÀÚ¿­À» °¡¸®Å°´Â Æ÷ÀÎÅÍÀÇ ¹è¿­À» µ¹·ÁÁØ´Ù.

				CommandLineToArgvw´Â ³»ºÎÀûÀ¸·Î ¸Þ¸ð¸®¸¦ ÇÒ´ÞÇÑ´Ù.
				´ëºÎºÐÀÇ ¾ÖÇÃ¸®ÄÉÀÌ¼ÇÀº ÀÌ·¸°Ô ÇÒ´çµÈ ¸Þ¸ð¸®¸¦ »èÁ¦ÇÏÁö ¾Ê´Â´Ù.
				¸Þ¸ð¸®´Â ¿î¿µÃ¼Á¦¿¡ ÀÇÇØ ÃßÀûµÇ¸ç, ÇÁ·Î¼¼½º°¡ Á¾·áµÇ´Â ½ÃÁ¡¿¡ ÀÚµ¿À¸·Î ÇØÁ¦µÈ´Ù.
				ÇÏÁö¸¸ ÀÌ Á¶Â÷µµ ¸í½ÃÀûÀ¸·Î »èÁ¦ÇÏ°íÀÚ ÇÑ´Ù¸é ´ÙÀ½°ú °°ÀÌ HeapFreeÇÔ¼ö¸£ È£ÃâÇÏ¸é µÈ´Ù.

			3. ÇÁ·Î¼¼½ºÀÇ È¯°æº¯¼ö
				
				¸ðµç ÇÁ·Î¼¼½º´Â ÀÚ±â ÀÚ½Å°ü ¿¬°üµÈ È¯°æºí·Ï(environment block)À» °¡Áö°í ÀÖ´Ù.
				È¯°æºí·ÏÀÌ¶õ ÇÁ·Î¼¼½ºÀÇ ÁÖ¼Ò°ø°£¿¡ ÇÒ´çµÈ ¸Þ¸ð¸® ºí·ÏÀ» ÀÇ¹ÌÇÏ¸ç, ÀÌ °ø°£Àº ´ÙÀ½°ú °°Àº ÇüÅÂ·Î ÀÏ·ÃÀÇ ¹®ÀÚ¿­À» Æ÷ÇÔÇÏ°í ÀÖ´Ù.

					=::=::\ ...
					VarName1=VarValue\0
					VarName2 = VarValue\0
					VarName3 = VarValue\0
					VarNameX = VarValue\0
					\0
				°¢ ¹®ÀÚ¿­ÀÇ Ã¹ ¹ø¤Š ºÎºÐÀº È¯°æº¯¼öÀÇ ÀÌ¸§ÀÌ´Ù.
				±× ´ÙÀ½À¸·Î ÇÒ´çÇÏ°íÀÚ ÇÏ´Â º¯¼öÀÇ °ªÀÌ ³ªÅ¸³­´Ù.
				°¡Àå ¾ÕÂÊÀÇ = :: = ::\¹®ÀÚ¿­°ú ´õºÒ¾î ºí·Ï ³»¿¡´Â =·Î ½ÃÀÛÇÏ´Â ´Ù¸¥ ¹®ÀÚ¿­µéÀÌ ÀÖ´Ù.
				=·Î ½ÃÀÛÇÏ´Â ¹®ÀÚ¿­Àº È¯°æº¯¼ö·Î »ç¿ëµÇ´Â ¹®ÀÚ¿­ÀÌ ¾Æ´Ï´Ù.

				È¯°æºí·Ï¿¡ Á¢±ÙÇÏ´Â µÎ °¡Áö ¹æ¹ýÀÌ ÀÖ´Ù.(¼­·Î ´Ù¸¥ ÆÄ½Ì¹æ½ÄÀ» »ç¿ëÇÏ±â ¶§¹®¿¡ ¼­·Î »óÀÌÇÑ ¸éÀÌ ¾øÁö ¾Ê´Ù.)
					- ÀüÃ¼ È¯°æºí·ÏÀ» ¾ò±â À§ÇØ GetEnvironmentStrings ÇÔ¼ö¸¦ È£ÃâÇÏ´Â °ÍÀÌ¸ç,
						GetEnvironmentString¿¡ ÀÇÇØ ¹ÝÈ¯µÈ ¸Þ¸ð¸® ºí·ÏÀ» ´õ ÀÌ»ó »ç¿ëÇÏÁö ¾ÊÀ» °ÍÀÌ¶ó¸é FreeEnvironmentStrings ÇÔ¼ö¸¦ È£­ŒÇÏ¿© ¸Þ¸ð¸®¸¦ ¹ÝÈ¯ÇØ¾ßÇÑ´Ù.
							
							BOOL FreeEnvironmentStrings(PTSTR pszEnvironmentBlock);

				-CUI¾ÖÇÃ¸®ÄÉÀÌ¼Ç¸¸ È°¿ë °¡´ÉÇÑ ¹æ¹ýÀ¸·Î _tmain ÁøÀÔÁ¡ ÇÔ¼öÀÇ ¸Å°³º¯¼ö·Î Àü´ÞµÇ´Â TCHAR * env[]¸¦  »ç¿ëÇÏ´Â °ÍÀÌ´Ù.
					GetEnvironmentStrings°¡ ¹ÝÈ¯ÇÏ´Â ³»¿ë°ú´Â ´Ù¸£°Ô env´Â ¹®ÀÚ¿­À» °¡¸®Å°´Â Æ÷ÀÎÅÍÀÇ ¹è¿­·Î ±¸¼ºµÇ¾î ÀÖÀ¸¸ç, °¢°¢ÀÇ Æ÷ÀÎÅÍ´Â "ÀÌ¸§=°ª"ÇüÅÂÀÇ ¹®ÀÚ¿­À» °¡¸®Å°°í ÀÖ´Ù.
					env¸¦ ÅëÇØ È¯°æº¯¼öµéÀÌ Àü´ÞµÇ±â ÀÌÀü¿¡ = ·Î ½ÃÀÛÇÏ´Â ¹®ÀÚ¿­µéÀº ¸ðµÎ Á¦°ÅµÈ »óÅÂ°¡ µÈ´Ù.µû¶ó¼­ ÀÌ¿¡ ´ëÇÑ Ã³¸®¸¦ µû·Î ÇØÁÙ ÇÊ¿ä°¡ ¾ø´Ù.

					= Àº È¯°æº¯¼öÀÇ ÀÏ¹Ç°ú °ªÀ» ±¸ºÐÇÏ´Â ±¸ºÐÀÚ ¿ªÈ°µµ ÇÏ±â ¶§¹®¿¡ È¯°æº¯¼ö ÀÌ¸§¿¡ = °¡ Æ÷ÇÔµÇ¾î¼­´Â ¾ÈµÈ´Ù.¶ÇÇÑ °ø¹é ¹®ÀÚµµ Áß¿äÇÏ´Ù.

				»ç¿ëÀÚ°¡ À©µµ¿ì¿¡ ·Î±×¿ÂÀ» ÇÏ¸é ½Ã½ºÅÛÀº ½© ÇÁ·Î¼¼½º¸¦ »ý¼ºÇÏ°í ÀÌ·Ö °ü·ÃµÈ È¯°æ ¹®ÀÚ¿­µéÀº ¼³Á¤ÇØÁØ´Ù.
				½Ã½ºÅÛÀº ÃÊ±â È¯°æ ¹®ÀÚ¿­ ¼³Á¤ °ªÀ» ·¹Áö½ºÆ®¸®ÀÇ µÎ ±ºµ¥ À§Ä¡·ÎºÎÅÍ °¡Á®¿Â´Ù.

				»ç¿ëÀÚ´Â Á¦¾îÆÇÀÇ ½Ã½ºÅÛÀ» ÅëÇØ ÀÌ·¯ÇÑ È¯°æº¯¼ö¸£ Ãß°¡, »èÁ¦, º¯°æÇÒ ¼ö ÀÖ´Ù.

				¾ÖÇÃ¸®ÄÉÀÌ¼ÇÀº ´Ù¾çÇÑ ·¹ÁþÆ®¸® °ü·Ã ÇÔ¼ö¸¦ »ç¿ëÇÏ¿© ·¹Áö½ºÆ®¸® Ç×¸ñÀ» ¼öÁ¤ÇÒ ¼ö ÀÖ´Ù.
				±×·±µ¥ ÀÌ·¯ÇÑ ·¹Áö½ºÆ®¸®ÀÇ º¯°æ»çÇ×ÀÌ ¸ðµç ¾ÖÇÃ¸®ÄÉÀÌ¼Ç¿¡ ¹Ý¿µµÇ±â¸¦ ¿øÇÑ´Ù¸é »ç¿ëÀÚ´Â ¹Ýµå½Ã ·Î±×¿ÀÇÁÇÑ ÈÄ ´Ù½Ã ·Î±×¿Â ÇØ¾ßÇÑ´Ù.

				¸î¸î ¾ÖÇÃ¸®ÄÉÀÌ¼ÇµéÀº ±×µéÀÇ ÁÖ À©µµ¿ì°¡ WM_SETTINGCHANGE ¸Þ½ÃÁö¸¦ ¼ö½ÅÇÏ¸é È£³ª°æºí·ÏÀ» »õ·Î¿î ·¹Áö½ºÆ®¸® Ç×¸ñÀ»È£ ¼öÁ¤ÇÒ ¼ö ÀÖµµ·Ï ÀÛ¼ºµÇ¾î ÀÖ´Ù.

				ÀÏ¹ÝÀûÀ¸·Î ÀÚ½Ä ÇÁ·Î¼¼½º´Â ºÎ¸ð ÇÁ·Î¼¼½ºÀÇ È¯°æº¯¼ö ÁýÇÕÀ» ±×´ë·Î »ó¼ÓÇÑ´Ù.
				ÇÏÁö¸¸ ºÎ¸ð ÇÁ·Î¼¼½º´Â ¾î¶² È¯°æº¯¼ö¸¦ ÀÚ½Ä ÇÁ·Î¼¼½º¿¡°Ô »ó¼ÓÇØ ÁÙÁö Á¦¾îÇÒ ¼ö ÀÖ´Ù.
				»ó¼ÓÀ» ÅëÇØ È¯°æº¯¼ö°¡ ÀÚ½Ä ÇÁ·Î¼¼½º·Î Àü´ÞµÇ¸é ºÎ¸ð ÇÁ·Î¼¼½º´Â È¯°æºí·ÏÀ» ÀÚ½Ä ÇÁ·Î¼¼½º¿Í °øÀ¯ÇÏ´Â °ÍÀÌ ¾Æ´Ï¶ó »õ·Ó°Ô º¹»çµÇ¾î Àü´ÞµÈ´Ù.

				µû¶ó¼­ ÀÚ½Ä ÇÁ·Î¼¼½º°¡ ÀÚ½ÅÀÇ È¯°æºí·Ï¿¡ »õ·Î¿î È¯°æº¯¼ö¸¦ Ãß°¡, »èÁ¦, º¯°æÇÑ´Ù ÇÏ´õ¶óµµ ºÎ¸ð ÇÁ·Î¼¼½ºÀÇ È¯°æºí·Ï¿¡´Â ¿µÇâÀ» ¹ÌÄ¡Áö ¾Ê´Â´Ù.

				¾ÖÇÃ¸®ÄÉÀÌ¼ÇÀº ÀÏ¹ÝÀûÀ» È¯°æº¯¼ö¸¦ ÀÌ¿ëÇÏ¿© »ç¿ëÀÚ°¡ ¾ÖÇÃ¸®ÄÉÀÌ¼¢ÀÇ µ¿ÀÛ ¹æ½ÄÀ» ÀûÀýÈ÷ º¯°æÇÒ ¼ö ÀÖµµ·Ï ÇÑ´Ù.
				»ç¿ëÀÚ°¡ È¯°æº¯¼ö¸¦ »ý¼ºÇÏ°í ÃÊ±âÈ­ÇÑ ÈÄ ¾ÖÇÃ¸®ÄÉÀÌ¼ÇÀ» ½ÇÇàÇÏ¸é, ½ÇÇàµÈ ¾ÖÇÃ¸®ÄÉÀÌ¼ÇÀº È¯°æºí·ÏÀÇ º¯¼öµéÀ» ÀÌ¿ëÇÒ ¼ö ÀÖÀ¸¸ç, 
				¾à¼ÓµÈ È¯°æº¯¼ö °ªÀ» Ã£°Ô µÇ¸é ÀÌ °ªÀ» ºÐ¼®ÇÏ¿© ¾ÖÇÃ¸®ÄÉÀÌ¼ÇÀÇ µ¿ÀÛ ¹æ½ÄÀ» º¯°æÇÒ ¼ö ÀÖ´Ù.

				È¯°æº¯¼öÀÇ ¹®Á¦Á¡Àº »ç¿ëÀÚ°¡ ±× °ªÀ» ¼³Á¤ÇÏ°Å³ª ÀÌÇØÇÏ´Â °ÍÀÌ ½±Áö ¾Ê´Ù´Â °ÍÀÌ´Ù.
				»ç¿ëÀÚ´Â º¯¼ö ÀÌ¸§»Ó¸¸ ¾Æ´Ï¶ó º¯¼ö °ªÀ» ¾î¶² Çü½ÄÀ» ¼³Á¤ÇØ¾ß ÇÒÁö¿¡ ´ëÇØ¼­µµ Á¤È®È÷ ¾Ë°í ÀÖ¾î¾ßÇÑ´Ù.
				GUI ±â¹Ý ¾ÖÇÃ¸®ÄÉÀÌ¼Ç¿¡¼­´Â »ç¿ëÀÚ°¡ ¾ÖÇÃ¸®ÄÉÀÌ¼ÇÀÇ µ¿ÀÛ ¹æ½ÄÀ» º¯°æÇÒ ¼ö ÀÖµµ·Ï ÇÏ±â À§ÇØ ´ÙÀÌ¾ó·Î±× ¹Ú½º¸¦ È°¿ëÇÑ´Ù.
				ÀÌ·¯ÇÑ Á¢±Ù ¹æ½ÄÀº ³»ºÎÀûÀ¸·Î È¯°æº¯¼ö¸¦ ÀÌ¿ëÇÏµµ·Ï ±¸ÇöµÇ¾ú´Ù ÇÏ´õ¶óµµ »ç¿ëÀÚ°¡¿¡°Ô Á» ´õ Ä£¼÷ÇÑ ¹æ¹ýÀÌ´Ù.

					DWORD GetEnvionmentVariable(
						PCTSTR pszName,
						PTSTR pszValue,
						DWORD cchvalue);

				GetEnvionmentVariableÀ» È£ÃâÇÒ ¶§ pszNameÀ¸·Î´Â È¯°æº¯¼öÀÇ ÀÌ¸§À» °¡¸®Å°´Â Æ÷ÀÎÅÍ¸¦ Àü´ÞÇØ¾ß ÇÏ°í,
				pszValue·Î´Â È¯°æº¯¼öÀÇ °ªÀ» ÀúÀåÇÒ ¹öÆÛ¸¦ °¡¸®Å°´Â Æ÷ÀÎÅÍ¸¦ Àü´ÞÇØ¾ß ÇÑ´Ù.
				cchValue´Â ¹öÆÛÀÇ Å©±â¸¦¹®ÀÚ ´ÜÀ§·Î Àü´ÞÇÏ¸é µÈ´Ù.
				ÀÌ ÇÔ¼ö´Â ¹öÆÛ·Î º¹»çµµ´Ï ¹®ÀÚÀÇ °³¼ö¸£ ¹ÝÈ¯ÇÏ°Å³ª, È¯°æºí·Ï¿¡ ÁÖ¾îÁø È¯°æº¯¼ö°¡ Á¸ÀçÇÏÁö ¾ÊÀ» °æ¿ì 0À» ¹ÝÈ¯ÇÑ´Ù.
				ÇÏÁö¸¸ È¯°æº¯¼öÀÇ °ªÀ» ÀúÀåÇÏ±â À§ÇØ ¾ó¸¶¸¸Å­ÀÇ ¹öÆÛ°¡ ÇÊ¿äÇÒÁö ¹Ì¸® ¾Ë ¼ö ¾ø´Ù¸é GetEnvionmentVariable ÇÔ¼ö¸¦ È£ÃâÇÒ ¶§ cchValue ¸Å°³º¯¼ö·Î 0À» Àü´ÞÇÏ¿©
				È¯°æº¯¼ö °ªÀ» ÀúÀåÇÏ´Â µ¥ ÇÊ¿äÇÑ ¹®ÀÚ ´ÜÀ§ÀÇ ¹öÆÛÅ©±â¿¡ ¹®ÀÚ¿­ Á¾°á('\0')¹®ÀÚ¸¦ ÀúÀåÇÒ °ø°£À» ´õÇÑ °ªÀ» ¾ò¾î¿Ã ¼ö ÀÖ´Ù.

				È¯°æº¯¼ö °ª¿¡´Â ´ëÃ¼ °¡´É ¹®ÀÚ¿­(replaceable string)ÀÌ Æ÷ÇÔµÇ¾î ÀÖ´Â °æ¿ì°¡ ¸¹´Ù.
				%·Î °¨½Ñ ºÎºÐÀº ´ëÃ¼ °¡´É ¹®ÀÚ¿­À» ÀÇ¹ÌÇÏ¸ç, ÀÌ °æ¿ì USERPROFILE È¯°æº¯¼ö °ªÀº ´Ù¸¥ ¹®ÀÚ¿­·Î º¯°æµÇ¾î¾ß ÇÑ´Ù.

				´ëÃ¼ °¡´É ¹®ÀÚ¿­¿¡ ´ëÇÑ º¯°æ ÀÛ¾÷Àº ¸Å¿ì ÀÏ¹ÝÀûÀÎ °ÍÀÌ±â ¶§¹®¿¡ À©µµ¿ì´Â ÀÌ¸¦ À§ÇØ ´ÙÀ½°ú °°ÀÌ ExpandEnvironmentStrings ÇÔ¼ö¸¦ Á¦°øÇÑ´Ù.

					DWORD ExpandEnvironmentStrings(
						PTCSTR pszSrc,
						PTSTR pszDst,
						DWORD chSize);

				ÀÌ ÇÔ¼ö¸¦ È£ÃâÇÒ ¶§ pszSrc ¸Å°³º¯¼ö·Î´Â ´ëÃ¼ °¡´É È¯°æº¯¼ö ¹®ÀÚ¿­À» Æ÷ÇÔÇÑ ¹®ÀÚ¿­ÀÇ ÁÖ¼Ò¸¦ Àü´ÞÇÏ¸é µÈ´Ù.
				pszDst ¸Å°³º¯¼ö·Î´Â º¯°æµÈ ¹®ÀÚ¿­ÀÌ ÀúÀåµÉ ¹öÆÛÀÇ ÁÖ¼Ò¸£ Àü´ÞÇÏ°í,
				chSize ¸Å°³º¯¼ö·Î´Â ¹öÆÛÀÇ ÃÖ´ë Å©±â¸¦ ¹®ÀÚ ´ÜÀ§·Î Àü´ÞÇÏ¸é µÈ´Ù.

				ÀÌ ÇÔ¼ö´Â º¯°æµÈ ¹®ÀÚ¿­À» ÀúÀåÇÏ´Â µ¥ ÇÊ¿äÇÑ ¹öÆÛÀÇ Å©±â¸¦ ¹®ÀÚ ´ÜÀ§·Î ¹ÝÈ¯ÇØ ÁØ´Ù.
				¸¸ÀÏ chSize°¡ º¯°æµÈ ¹®ÀÚ¿­À» ÀúÀåÇÏ±â¿¡ ÃæºÐÇÏÁö ¾ÊÀ¸¸é ´ëÃ¼ °¡´É ¹®ÀÚ¿­Àº º¯°æµÇÁö ¾ÊÀ¸¸ç, ´ë½Å ºó ¹®ÀÚ¿­·Î º¯°æµÈ´Ù.

				µû¶ó¼­, ExpandEnvironmentStrings ÇÔ¼ö´Â µÎ¹ø È£ÃâÇÏ´Â °ÍÀÌ ÀÏ¹ÝÀûÀÌ´Ù.
				
				¸¶Áö¸·À¸·Î È¯°æº¯¼ö¸¦ Ãß°¡, »èÁ¦ÇÏ°Å³ª È¯°æº¯¼ö °ªÀ» º¯°æÇÏ±â À§ÇØ SetEnvironmentVariable ÇÔ¼ö¸¦ »ç¿ëÇÒ ¼ö ÀÖ´Ù.

					BOOL SetEnvironmentVariable(
						PCTSTR pszName,
						PCTSTR pszValue);

				ÀÌ ÇÔ¼ö´Â pszName ¸Å°³º¯¼ö·Î Àü´ÞÇÑ °ªÀ» º¯¼öÀÇ ÀÌ¸§À¸·Î, pszValue ¸Å°³º¯¼ö·Î Àü´ÞÇÑ °ªÀ» º¯¼öÀÇ °ªÀ¸·Î ÇÏ¿© È¯°æº¯¼ö¸¦ ¼³Á¤ÇÑ´Ù.
				¸¸ÀÏ µ¿ÀÏ ÀÌ¸§ÀÇ È¯°æº¯¼ö°¡ ÀÌ¹Ì Á¸ÀçÇÏ´Â °æ¿ì ±âÁ¸ °ªÀ» ¼öÁ¤ÇÏ°Ô µÇ°Å, º¯¼ö°¡ ¾øÀ» °æ¿ì »õ·ÎÀÌ Ãß°¡ÇÏ°Ô µÈ´Ù.
				pszValue¿¡ nullÀ» ÁÖ°ÔµÇ¸é È¯°æº¯¼ö ºí·ÏÀ¸·ÎºÎÅÍ ÁÖ¾îÁø È¯°æº¯¼ö¸¦ Á¦°ÅÇÑ´Ù.

			4. ÇÁ·Î¼¼½ºÀÇ ¼±È£µµ
					
				ÇÁ·Î¼¼½º ³»¿¡ Á¸ÀçÇÏ´Â ½º·¹µåµéÀº ÄÄÇ»ÅÍ¿¡ ÀåÂøµÈ ¾î¶² CPU¿¡¼­µµ ¼öÇàµÉ ¼ö ÀÖ´Ù.
				ÇÏÁö¸¸ ÇÁ·Î¼¼½ºÀÇ ½º·¹µå°¡ °¡¿ë CPUµé Áß ÀÏºÎ CPU¿¡¼­¸¸ ¼öÇàµÇµµ·Ï ÇÒ ¼ö ÀÖ´Ù.
					ÀÌ°ÍÀ¸ ÇÁ·Î¼¼½º ¼±È£µµ¶ó°í ÇÑ´Ù. ÀÚ½Ä ÇÁ·Î¼¼½ºµéÀº ºÎ¸ð ÇÁ·Î¼¼½ºÀÇ ¼±È£µµ¸¦ »ó¼ÓÇÑ´Ù.

			5. ÇÁ·Î¼¼½ºÀÇ ¿¡·¯¸ðµå
						
				°¢°¢ÀÇ ÇÁ·Î¼¼½ºµéÀº µð½ºÅ© ¿¡·¯³ª Ã³¸®µÇÁö ¾ÊÀº ¿¹¿Ü, ÆÄÀÏ Ã£±â ½ÇÆÐ, µ¥ÀÌÅÍÀÇ ºñÁ¤·Ä µî°ú °°Àº ½É°¢ÇÑ ¿¡·¯¸¦ ¾î¶»°Ô Ã³¸®ÇÒÁö¸¦ ½Ã½ºÅÛ¿¡°Ô ¾Ë·ÁÁÖ±â À§ÇÑ ÀÏ·ÃÀÇ ÇÃ·¡±× °ªÀ» °¡Áö°í ÀÖ´Ù.
				ÀÚ½Ä ÇÁ·Î¼¼½º´Â ºÎ¸ð ÇÁ·Î¼¼½ºÀÇ ¿¡·¯¸ðµå ÇÃ·¡±×¸¦ »ó¼ÓÇÑ´Ù.
				Áï, ÇÁ·Î¼¼½º°¡ SEM_NOGPFAULTERROBPX ÇÃ·¡±×¸¦ ¼³Á¤ÇØ µÎ¸é ÀÌ ÇÁ·Î¼¼½º°¡ ¼öÇàÇÑ ÀÚ½Ä ÇÁ·Î¼¼½ºµµ µ¿ÀÏÇÑ ¼³Á¤À» »ó¼Ó¹Þ°Ô µÈ´Ù.
				ÇÏÁö¸¸ ÀÚ½Ä ÇÁ·Î¼¼½º´Â ÀÌ¿Í °°ÀÌ ¼³Á¤ÀÌ º¯°æµÇ¾ú´Ù´Â »ç½ÇÀ» Àü´Þ¹ÞÁö ¸øÇÏ±â ¶§¹®¿¡ ÀÏ¹Ý º¸È£ ½ÇÆÐ(general protection fault: GP ½ÇÆÐ)¸¦ Ã³¸®ÇÏ´Â ÄÚµå¸¦ ÀÛ¼ºÇÏÁö ¾Ê¾ÒÀ» ¼öµµ ÀÖ´Ù.
				GP ½ÇÆÐ°¡ ÀÚ½Ä ÇÁ·Î¼¼½ºÀÇ ½º·¹µåµé Áß ÇÏ³ª¿¡¼­ ¹ß»ýÇÏ¸é ÀÚ½Ä ÇÁ·Î¼¼½º´Â »ç¿ëÀÚ¿¡°Ô ¾Æ¹«·± ÅëÁö ¾øÀÌ Á¾·áµÇ¾î ¹ö¸± °ÍÀÌ´Ù.
				ºÎ¸ð ÇÁ·Î¼¼½º´Â ÀÚ½Ä ÇÁ·Î¼¼½º°¡ ¿¡·¯¸ðµå¸¦ »ó¼Ó¹ÞÁö ¾Êµµ·Ï ÇÏ±â À§ÇØ CreateProcess È£Ãâ ½Ã CREATE_DEFAULT_ERROR_MODE ÇÃ·¡±×¸¦ ÁöÁ¤ÇÒ ¼ö ÀÖ´Ù.

