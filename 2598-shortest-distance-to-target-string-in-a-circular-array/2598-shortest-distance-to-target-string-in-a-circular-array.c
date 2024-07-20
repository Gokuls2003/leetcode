int closetTarget(char **words, int wordsSize, char *target, int startIndex){
    int n = wordsSize;
    int leftDist = -1, rightDist = -1;

    bool targetExists = false;
    for (int i = 0; i < n; i++) {
        if (strcmp(words[i], target) == 0) {
            targetExists = true;
            break;
        }
    }

    if (!targetExists) {
        return -1;
    }

    int currIndex = startIndex;
    for (int i = 0; i < n; i++) {
        if (strcmp(words[currIndex], target) == 0) {
            leftDist = i;
            break;
        }
        currIndex = (currIndex + 1) % n;
    }

    currIndex = startIndex;
    for (int i = 0; i < n; i++) {
        if (strcmp(words[currIndex], target) == 0) {
            rightDist = i;
            break;
        }
        currIndex = (currIndex - 1 + n) % n;
    }

    if (leftDist == -1 && rightDist == -1) {
        return -1;
    } else if (leftDist == -1) {
        return rightDist;
    } else if (rightDist == -1) {
        return leftDist;
    } else {
        return (leftDist < rightDist) ? leftDist : rightDist;
    }
}