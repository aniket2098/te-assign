Create()
{
    echo "Enter number of records"
    read no
    while [ $no -gt 0 ]
    do
    no=`expr $no - 1`
    echo "Enter Name: "
    read name
    echo "Enter Phone no.:"
    read tel_no
    echo "Enter Address: "
    read addr
    
    
    done
}

echo "Enter your choice:\n1)Create an address book\n2)View address book\n3)Insert a record\n4)Delete a record\n5)Modify a rec\n6)Exit"
read choice
case "$choice" in
1)Create;;
2);;
3);;
4);;
5);;
6);;
*)echo "Wrong Choice!\nRe-enter";;
esac


