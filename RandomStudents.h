#include "resource.h"
/*#define Min 1
#define Max 9
#define Amount 3*/
void DefToConfig(void) {
    FILE* cfg = fopen("studentsconfig.ini", "w+");
        
    fprintf(cfg, "minimum_number=1\n\
maximum_number=60\n\
amount=3\n\
title_of_message_box=��ϲ����ͬѧ�����У�\n\
content_of_message_box=�� %%s ��ͬѧ��");
    fclose(cfg);
}

    

void Random() {
    wchar_t ran[10][100] = { 0 },
        msgTitle[100]=L"��ϲ����ͬѧ�����У�",
        msgContent[100]=L"�� %s ��ͬѧ��",
        contentOut[100];
    int num[100],Min=1,Max=60,Amount=3;

    //���������ļ�
    FILE* test = fopen("studentsconfig.ini", "r");
    if (test == NULL) {
        
        DefToConfig();
    }
    FILE* rdcfg = fopen("studentsconfig.ini", "r");
    int dbg = fscanf(rdcfg, "minimum_number=%d\n\
maximum_number=%d\n\
amount=%d\n\
title_of_message_box=%s\n\
content_of_message_box=%s", &Min, &Max, msgTitle, msgContent);
    fclose(rdcfg);


    //��������ɹ���
    default_random_engine e;
    uniform_int_distribution<int> u(Min, Max); // ����ұ�����
    e.seed(time(0));

    for (int i = 0; i <= (Amount -1); i++) {
        num[i] = u(e);
        if(i!= Amount -1)wsprintf(ran[i], L"%d, ", num[i]);
        else wsprintf(ran[i], L"%d", num[i]);
        //MessageBox(NULL, ran[i], L"  ", MB_OK);
        
    }
    for (int i = 0; i <= (Amount - 1); i++) {
        lstrcatW(ran[0], ran[i + 1]);
    }

    //������������
    lstrcatW(ran[0], L"\0");
    wsprintf(contentOut, msgContent, ran[0]);
    MessageBox(NULL, contentOut, msgTitle, MB_OK|MB_ICONINFORMATION);
}

