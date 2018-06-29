Create()
{
    no=1
    if [ $# -le 0 ]
    then
        echo "Enter number of records"
        read no
    fi
    while [ $no -gt 0 ]
    do
    no=`expr $no - 1`
    echo "Enter Name: "
    read name
    echo "Enter Phone no.:"
    read tel_no
    echo "Enter Address: "
    read addr
    echo $name"\t"$tel_no"\t"$addr>>records.txt
    done
    sort records.txt>records1.txt
    mv records1.txt records.txt
}

View()
{
    echo "Name\tPhone\t\tAddress\n"
    cat records.txt
    echo "\t"
}

Delete()
{
    echo "Enter Record Name to be deleted:"
    read key
    sed  /$key/d records.txt>records1.txt
    mv records1.txt records.txt 
}

Modify()
{
    echo "Enter record Name to be modified:"
    read key
    echo "Enter new phone no.:"
    read newNo
    echo "Enter new address:"
    read newAddr
    sed /$key/c\ "$key\t$newNo\t$newAddr" records.txt>records1.txt
    mv records1.txt records.txt
}

touch records.txt

while true
do
    echo "Enter your choice:\n1)Create an address book\n2)View address book\n3)Insert a record\n4)Delete a record\n5)Modify a rec\n6)Exit"
    read choice
    case "$choice" in
        1) Create;;
        2) View;;
        3) Create 1;;
        4) Delete;;
        5) Modify;;
        6) break;;
        *)echo "Wrong Choice!\nRe-enter";;
    esac
done
