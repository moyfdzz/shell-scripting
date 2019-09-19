BEGIN{
    sum = 0
    row = 1
}
{
    averages[row]=($2+$3+$4+$5+$6)/5
    row++
}
END{
    sumAverage = 0

    for(i = 2; i < row; i++) {
        sumAverage += averages[i]
        print averages[i]
    }

    average = sumAverage / 5

    SDAverage = 0

    for(i = 2; i < row; i++) {
        SDAverage += (averages[i] - average) ^ 2
    }

    print sqrt(SDAverage / 5)
}