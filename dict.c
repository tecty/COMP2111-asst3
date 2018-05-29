#include "dict.h"
#include <stdio.h>
#include <stdlib.h>
void newdict(Dict *dp){
    // malloc the space of root node.
    *dp = malloc(sizeof(struct __tnode__));
}

void doAddword(const Dict r, const word w, int index) {
    if (w[index]!= '\0') {
        // the word is not ended
        if (r->cvec[w[index+1]-'a']!=NULL) {
            /* POPWORD(w,index+1) \in dom(t) */
            // skip
        }
        else{
            // t:= (POPWORD(w,index+1) -> 0)
            newdict(&(r->cvec[w[index+1]-'a']));
        }
        // recursive call
        doAddword(r->cvec[w[index+1]-'a'],w , index +1);
    }
    else{
        // index = |w|
        // t:= t_0 \{w -> 0} U {w -> 1}
        r->eow = TRUE;
    }
}

bool doCheckword(const Dict r, const word w, int index){
    if (w[index]!= '\0') {
        // the word is not ended
        if (r->cvec[w[index+1]-'a']!=NULL) {
            /* POPWORD(w,index+1) \in dom(t) */
            // skip
        }
        else{
            // t:= (POPWORD(w,index+1) -> 0)
            // there is not exist the word in this dict
            return FALSE;
        }
        // recursive call
        return doCheckword(r->cvec[w[index+1]-'a'],w , index +1);
    }
    else{
        // index = |w|
        // return b:= (t(w) = 1)
        return r->eow;
    }
}

void doDelword(const Dict r, const word w, int index) {
    if (w[index]!= '\0') {
        // the word is not ended
        if (r->cvec[w[index+1]-'a']!=NULL) {
            /* POPWORD(w,index+1) \in dom(t) */
            // recursive call
            doDelword(r->cvec[w[index+1]-'a'],w, index+1);
        }
        else{
            // t:= (POPWORD(w,index+1) -> 0)
            // there is not exist the word in this dict
            // nothing to delete
            // skip;
            return;
        }
    }
    else{
        // index = |w|
        // return t:= t: w-> 0
        r->eow = FALSE;
    }
}

void addword (const Dict r, const word w){
    doAddword(r, w,0);
}
bool checkword (const Dict r, const word w){
    return doCheckword(r, w,0);
}
void delword (const Dict r, const word w){
    doDelword(r,w, 0);
}
void barf(char *s){
    fprintf(stderr, "%s\n",s);
}
