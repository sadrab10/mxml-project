#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "mxml.h"

int main() {

	FILE *fp;
    	mxml_node_t *tree;
	mxml_node_t *node_current;
	char buffer[4096];
	int size = 0;

    	fp = fopen("test2.xml", "r");
    	tree = mxmlLoadFile(NULL, fp, MXML_TEXT_CALLBACK);


 	node_current = mxmlFindPath(tree, "data/node");
	/*node_current = mxmlFindElement(tree, tree, "data",
                           NULL, NULL,
                           MXML_DESCEND);*/
	/*node_current = mxmlFindElement(node_current, tree, "node",
                           NULL, NULL,
                           MXML_DESCEND);*/
	size = mxmlSaveString(node_current, buffer, 4096, MXML_NO_CALLBACK);

	//printf("hello world!\n");
	printf("%s", buffer);
	mxmlDelete(tree);
    	fclose(fp);
	
	return 0;

}
