//
//  CBPage40_2_3.c
//  CBMacOSX&iOSDemo
//
//  Created by ChenBin on 2016/12/29.
//  Copyright © 2016年 ChenBin. All rights reserved.
//

#include <ApplicationServices/ApplicationServices.h>

void say (int voice, char *text) {
    OSErr rc;
    SpeechChannel channel;
    VoiceSpec vs;
    
    rc = GetIndVoice(voice, &vs);
    rc = NewSpeechChannel(&vs, &channel);
    rc = SpeakText(channel, text, strlen(text));
    if (rc) {
        fprintf(stderr, "Unable to speak!\n");
        exit(1);
    }
    while (SpeechBusy()) {
        sleep(1);
    }
    exit(0);
}
