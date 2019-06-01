declare -a var=("QI10" "QPE")
declare -a vec=("OrdC" "OrdD")
declare -a tam=("50000" "100000" "150000" 
                  "200000" "250000" "300000" 
                )

for i in "${var[@]}"
do
    for j in "${vec[@]}"
    do
        for k in "${tam[@]}"
        do
            ./bin/main $i $j $k
        done
    done
done
