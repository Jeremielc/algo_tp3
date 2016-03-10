if (string == "\0") {
    return;
}

if (tree->value == string[i]) {
    if (tree->son != NULL) {
        insertion(string + 1, tree->son);
    } else {
        NODE* node;
        tree->son = node;
        insertion(string + 1, tree->son);
    }

    return;
} else if (tree->value != string[i]) {
    NODE* node = tree;
    while (tree->brother != NULL) {
        node = tree->brother;

        if (node->value == string[i]) {
            if (node->son != NULL) {
                insertion(string + 1, node->son);
            } else {
                NODE* other;
                node->son = other;
                insertion(string + 1, node->son);
            }

            return;
        }
    }

    NODE* other;
    node->brother = other;
    insertion()
}
