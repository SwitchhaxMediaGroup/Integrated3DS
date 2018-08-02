#include <3ds.h>
#include <stdio.h>


int main(int argc, char **argv)
{
	//base code from Hello world example in devkitpro/examples i think
	aptInit();
    gfxInitDefault();
    hidInit();
    gspLcdInit();
    consoleInit(GFX_TOP, NULL);
	
	
	/*
	Message:
	This is crap code IK i wrote it in like 40 minutes and it seems fine
	please test and if it doesn't work well fix it thanks :)
	*/
	
	
	
	
	//booleans to use for if statements "detecting" stuff
	bool cfw = false;
	bool a9lh = false;
	bool b9s = false;
	bool unknownfw = false;
	bool ninedoto = false;
	printf("Integrated3DS v1\n");
	
	
	
	
	FILE* bootfirm = fopen("/boot.firm", "r");
if(bootfirm)
{
    printf("CFW = true\n");
	cfw = true;
	b9s = true;
    fclose(bootfirm);
}else{
printf("CFW = false\n");
unknownfw = true;
}
if(osGetKernelVersion() > SYSTEM_VERSION(2,46,0)){
	printf("Version is higher than 9.0\n");
	ninedoto = true;
}else{
	printf("Version is lower than 9.0\n");
}

if(b9s){
	printf("Running boot9strap\n");
}else{
	printf("Not running boot9strap\n");
}

printf("Start to exit\n");

	
	
	  bool isNew3DS = 0;
    APT_CheckNew3DS(&isNew3DS);
	//Credits to who ever made this i don't remember
    if (isNew3DS)
    {
        u8 Screens = 0;
        GSPLCD_GetVendors(&Screens);
        switch ((Screens >> 4) & 0xF)
        {
            case 1:
                printf("Top Screen: TN\n");
                break;
            case 0xC:
                printf("Top Screen: TN\n");
                break;
            default:
                printf("Could not detect!\n");
                break;
        }
         switch (Screens & 0xF)
        {
            case 1:
                printf("Bottom Screen: IPS\n");
                break;
            case 0xC:
                printf("Bottom Screen: TN\n");
                break;
            default:
                printf("Could not detect!\n");
                break;
        }
    }
    else
    {
        printf("Can't detect old models sry.");
    }
	// Main loop
	while (aptMainLoop())
	{
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();

		//hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
		u32 kDown = hidKeysDown();

		if (kDown & KEY_START) break; // break in order to return to hbmenu

		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();

		//Wait for VBlank
		gspWaitForVBlank();
	}

	aptExit();
    gfxExit();
    hidExit();
    gspLcdExit();
	return 0;
}
