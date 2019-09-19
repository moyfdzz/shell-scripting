BEGIN{}
{
    a = $1
    c = $2
    b = c ^ 2 - a ^ 2

    if (b >= 0) {
        print sqrt(b)
    }
    else {
        print "Imposible"
    }
}
END{}