#include "search.h"

using namespace std;

const double k1 = 1.2;
const double b = 0.75;
void search(char* token, Trienode* trie, Mymap* map, int k)
{
    char warray[10][256];
    double IDF[10];
    token = strtok(NULL, " \t\n");
    Scorelist* scorelist = new Scorelist();
    int i;
    for (i = 0; i < 10; i++)
    {
        if (token == NULL)
            break;
        strcpy(warray[i], token);
        // idf =  (no of doc - no of doc it is present) / (no. of doc it is present)
        IDF[i] = log10(((double)map->getsize() - (double)trie->dsearchword(warray[i], 0) + 0.5) / ((double)trie->dsearchword(warray[i], 0) + 0.5));
        trie->search(warray[i], 0, scorelist);
        token = strtok(NULL, " \t\n");
    }
    double avgdl = 0;
    for (int m = 0; m < map->getsize(); m++)
        avgdl += (double)map->getlength(m);
    avgdl /= (double)map->getsize();
    double score = 0;
    Scorelist* templist = scorelist;
    Maxheap* heap = new Maxheap(k);
    int ceil = 0;
    // cout << 1  << endl;
    while (templist != NULL)
    {
        for (int l = 0; l < i; l++) {
            //score = summaation(  )
            score += IDF[l] * ((double)trie->tfsearchword(templist->getid(), warray[l], 0) * (k1 + 1.0)) / ((double)trie->tfsearchword(templist->getid(), warray[l], 0) + k1 * (1.0 - b + b * (double)map->getlength(templist->getid()) / (double)avgdl));
        }
        heap->insert(score, templist->getid());
        score = 0;
        templist = templist->getnext();

        ceil++;
    }
    if (ceil > k)
        ceil = k;
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    // cout << w.ws_row << endl;
    for (int l = 0; l < ceil; l++) {

        int id = heap->getid();
        if (id == -1) {
            break;
        }
        double score = (double)heap->remove();
        cout << "(" << id ;
        int x = 10;
        int f = 1;
        while (id / x != 0) {
            x *= 10;
            f++;
        }
        while (5 - f >= 0) {
            cout <<  " " ;
            f++;
        }
        printf(")[%10.6f]", score);
        char* line = (char*)malloc(map->getbuffersize() * sizeof(char));
        strcpy(line, map->getDocument(id));
        char* temp = strtok(line, " \t\n");
        int currlength = 0;
        int counter = 0;
        int newline = 1;
        int lineflag = 0;
        int underline[2][100];
        int ucounter = 0;

        while (temp != NULL) {
            if (newline) {
                currlength += 20;
                if (counter != 0) {
                    for (int co = 0; co < 20 ; co++) {
                        cout << " ";
                    }

                }
                newline = 0;
            }
            for (int n = 0; n < i; n++) {
                if (!strcmp(warray[n], temp)) {
                    if (currlength + strlen(temp) + 1 <= w.ws_col) {
                        underline[0][ucounter] = currlength;
                        underline[1][ucounter] = strlen(temp);
                        ucounter++;
                        lineflag = 1;
                    }
                    break;
                }
            }
            currlength += strlen(temp) + 1;
            // cout << "curlength-1=" << currlength - 1 << ", w.ws_col=" << w.ws_col << endl ;
            if (currlength - 1 >= w.ws_col) {
                currlength = 0;
                newline = 1;
                cout << endl;
                if (lineflag) {
                    char* outputline = (char*)malloc( (w.ws_col + 1) * sizeof(char) );
                    for (int j = 0; j < w.ws_col; j++) {
                        outputline[j] = ' ';
                    }
                    outputline[w.ws_col] = '\0';
                    for (int j = 0; j < ucounter; j++) {

                        for (int v = underline[0][j]; v < underline[0][j] +  underline[1][j]; v++) {
                            outputline[v] = '^';
                        }
                    }
                    ucounter = 0;
                    cout << outputline;
                    lineflag = 0;
                    // newline = 1;
                    free(outputline);
                }
                continue;
            }

            // cout << "here " << endl;
            cout << temp << " " ;
            temp = strtok(NULL, " \t\n");
            counter++;

        }
        cout << endl;
        free(line);
        free(temp);
    }
    delete(heap);
    delete(scorelist);
    cout << endl;
}

void df(Trienode* trie)
{
    char* token2;
    token2 = strtok(NULL, " \t\n");
    if (token2 != NULL)
        cout << token2 << " " << trie->dsearchword(token2, 0) << endl;
    else
    {
        char* buffer = (char*)malloc(256 * sizeof(char));
        memset(buffer, '\0', 256);
        trie->dsearchall(buffer, 0);
        free(buffer);
    }
    token2 = NULL;
    free(token2);
}

int tf(char* token, Trienode* trie)
{
    char* token2;
    token2 = strtok(NULL, " \t\n");
    if (token2 == NULL)
    {
        free(token2);
        return -1;
    }
    for (int l = 0; l < strlen(token2); l++)
    {
        if (!isdigit(token2[l]))
        {
            token2 = NULL;
            free(token2);
            return -1;
        }
    }
    int id = atoi(token2);
    token2 = strtok(NULL, " \t\n");
    if (token2 == NULL)
    {
        free(token2);
        return -1;
    }
    cout << id << " " << token2 << " " << trie->tfsearchword(id, token2, 0) << endl;
    return 1;
}