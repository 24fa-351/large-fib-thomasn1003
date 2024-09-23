for method in i r
do
    for num in {0..100}  # Adjust the range as needed
    do
        start=$(date +%s.%N)
        ./fibonacci $num $method >> /dev/null
        end=$(date +%s.%N)
        duration=$(echo "$end - $start" | bc)
        echo "$num,$method,$duration,unsigned long long" >> results.csv
    done
done