BEGIN {
    input[1] = "2"
    inputLength = 0;
}

  #Quita artículos y preposiciones /\y(chars a quitar)\y/
 /\ya\y/ || /\yde\y/ || /\yo\y/ || /\yal\y/ || /\yel\y/ || /\yy\y/ || /\yu\y/ || /\yuno\y/ || /\yunos\y/ || /\yuna\y/ || /\yunas\y/ {next}

{
    if (NR != 1 && $1 != currData) {
        printf "%s ", currData

        for (i = 1; i < inputLength-1; i++) {
            printf "%s, ", input[i]
        }

        printf "%s", input[inputLength-1]

        for (i = 1; i <= inputLength; i++) {
            delete input[i]
        }

        printf "\n"

        currData = $1
        inputLength = 1
        input[inputLength++] = $2
    } else {
        input[inputLength++] = $2
    }
}
END {
    printf "%s ", currData

    for (i = 1; i < inputLength-1; i++) {
        printf "%s, ", input[i]
    }

    printf "%s", input[inputLength-1]

    for (i = 1; i <= inputLength; i++) {
        delete input[i]
    }

    printf "\n"
}