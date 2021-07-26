#include "trienode.h"

Trienode::Trienode()
{
      this->isLast = 0;
      for (int i = 0; i < 256; i++)
            child[i] = NULL;

      this->list = NULL;
}
Trienode::~Trienode()
{
      if (list != NULL)
            delete(list);
      for (int i = 0; i < 256; i++)
            if (child[i])
                  delete child[i];

}

void Trienode::insert(char* token, int id) {

      Trienode *temp = this;
      int n = strlen(token);
      for (int i = 0; i < n; i++) {

            int ascii = (int)token[i];
            if (temp->child[ascii] == NULL) {
                  temp->child[ascii] = new Trienode();
            }
            temp = temp->child[ascii];

      }
      temp->isLast = 1;
      if (temp->list == NULL)
            temp->list = new listnode(id);
      temp->list->add(id);

}

int Trienode::tfsearchword(int id, char* word, int curr) {

      Trienode *temp = this;
      int n = strlen(word);

      for (int i = 0; i < n; i++) {

            int ascii = (int)word[i];
            if (temp->child[ascii] == NULL)
                  return 0;
            temp = temp->child[ascii];

      }
      if (temp->isLast)
            return temp->list->search(id);
      else return 0;

}

int Trienode::dsearchword(char* word, int curr) {

      Trienode *temp = this;
      int n = strlen(word);

      for (int i = 0; i < n; i++) {

            int ascii = (int)word[i];
            if (temp->child[ascii] == NULL)
                  return 0;
            temp = temp->child[ascii];

      }
      if (temp->isLast)
            return temp->list->volume();
      else return 0;

}
void Trienode::dsearchall(char* buffer, int curr)
{
      cout << "Not Updated all print..." << endl;
      // buffer[curr] = value;
      // if (list != NULL)
      //     cout << buffer << " " << list->volume() << endl;
      // if (child != NULL)
      //     child->dsearchall(buffer, curr + 1);
      // if (sibling != NULL)
      //     sibling->dsearchall(buffer, curr);
      // buffer[curr] = '\0';
}

void Trienode::search(char* word, int curr, Scorelist* scorelist)
{

      Trienode *temp = this;
      int n = strlen(word);

      for (int i = 0; i < n; i++) {

            int ascii = (int)word[i];
            if (temp->child[ascii] == NULL)
                  return;
            temp = temp->child[ascii];

      }
      if (temp->isLast ) {

            temp->list->passdocuments(scorelist);
      }

}