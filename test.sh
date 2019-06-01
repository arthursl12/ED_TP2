declare -a var=("QPE")
declare -a vec=("OrdD")
declare -a tam=("50000" "100000" "150000" 
                "200000" "250000" "300000" 
                "350000" "400000" "500000"
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
