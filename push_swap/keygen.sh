#!/bin/bash

is_sorted() {
  prev=0
  for i in $1; do
    if [[ $i -lt $prev ]]; then
      return 1
    fi
    prev=$i
  done
  return 0
}
count_instructions() {
  echo "$1" | grep -o -E "pa|pb|ra|rra|sa|sb|ss|ra|rb|rr" | wc -l
}

# Define a vibrant color palette
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[1;34m'
MAGENTA='\033[0;35m'
CYAN='\033[1;36m'
LIGHT_BLUE='\033[1;94m'
BRIGHT_YELLOW='\033[1;93m'
WHITE='\033[1;37m'
BOLD='\033[1m'
UNDERLINE='\033[4m'
RESET='\033[0m'

ascii_art="
${CYAN}═════════════════════════════════════════════════════════════════════════════════
${MAGENTA}▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
${MAGENTA}▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
${MAGENTA}
      :::    ::: :::::::::: :::   :::  ::::::::  :::::::::: ::::    ::: 
     :+:   :+:  :+:        :+:   :+: :+:    :+: :+:        :+:+:   :+:  
    +:+  +:+   +:+         +:+ +:+  +:+        +:+        :+:+:+  +:+   
   +#++:++    +#++:++#     +#++:   :#:        +#++:++#   +#+ +:+ +#+    
  +#+  +#+   +#+           +#+    +#+   +#+# +#+        +#+  +#+#+#     
 #+#   #+#  #+#           #+#    #+#    #+# #+#        #+#   #+#+#      
###    ### ##########    ###     ########  ########## ###    ####       

${MAGENTA}▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
${MAGENTA}▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
"
test_cases_2_numbers=(
  "1 2"
  "2 1"
)
test_cases_3_numbers=(
  "1 2 3"
  "1 3 2"
  "2 1 3"
  "2 3 1"
  "3 1 2"
  "3 2 1"
)
test_cases_4_numbers=(
  "1 2 3 4"
  "1 2 4 3"
  "1 3 2 4"
  "1 3 4 2"
  "1 4 2 3"
  "1 4 3 2"
  "2 1 3 4"
  "2 1 4 3"
  "2 3 1 4"
  "2 3 4 1"
  "2 4 1 3"
  "2 4 3 1"
  "3 1 2 4"
  "3 1 4 2"
  "3 2 1 4"
  "3 2 4 1"
  "3 4 1 2"
  "3 4 2 1"
  "4 1 2 3"
  "4 1 3 2"
  "4 2 1 3"
  "4 2 3 1"
  "4 3 1 2"
  "4 3 2 1"
)
test_cases_5_numbers=(
  "1 2 3 4 5"
  "1 2 3 5 4"
  "1 2 4 3 5"
  "1 2 4 5 3"
  "1 2 5 3 4"
  "1 2 5 4 3"
  "1 3 2 4 5"
  "1 3 2 5 4"
  "1 3 4 2 5"
  "1 3 4 5 2"
  "1 3 5 2 4"
  "1 3 5 4 2"
  "1 4 2 3 5"
  "1 4 2 5 3"
  "1 4 3 2 5"
  "1 4 3 5 2"
  "1 4 5 2 3"
  "1 4 5 3 2"
  "1 5 2 3 4"
  "1 5 2 4 3"
  "1 5 3 2 4"
  "1 5 3 4 2"
  "1 5 4 2 3"
  "1 5 4 3 2"
  "2 1 3 4 5"
  "2 1 3 5 4"
  "2 1 4 3 5"
  "2 1 4 5 3"
  "2 1 5 3 4"
  "2 1 5 4 3"
  "2 3 1 4 5"
  "2 3 1 5 4"
  "2 3 4 1 5"
  "2 3 4 5 1"
  "2 3 5 1 4"
  "2 3 5 4 1"
  "2 4 1 3 5"
  "2 4 1 5 3"
  "2 4 3 1 5"
  "2 4 3 5 1"
  "2 4 5 1 3"
  "2 4 5 3 1"
  "2 5 1 3 4"
  "2 5 1 4 3"
  "2 5 3 1 4"
  "2 5 3 4 1"
  "2 5 4 1 3"
  "2 5 4 3 1"
  "3 1 2 4 5"
  "3 1 2 5 4"
  "3 1 4 2 5"
  "3 1 4 5 2"
  "3 1 5 2 4"
  "3 1 5 4 2"
  "3 2 1 4 5"
  "3 2 1 5 4"
  "3 2 4 1 5"
  "3 2 4 5 1"
  "3 2 5 1 4"
  "3 2 5 4 1"
  "3 4 1 2 5"
  "3 4 1 5 2"
  "3 4 2 1 5"
  "3 4 2 5 1"
  "3 4 5 1 2"
  "3 4 5 2 1"
  "3 5 1 2 4"
  "3 5 1 4 2"
  "3 5 2 1 4"
  "3 5 2 4 1"
  "3 5 4 1 2"
  "3 5 4 2 1"
  "4 1 2 3 5"
  "4 1 2 5 3"
  "4 1 3 2 5"
  "4 1 3 5 2"
  "4 1 5 2 3"
  "4 1 5 3 2"
  "4 2 1 3 5"
  "4 2 1 5 3"
  "4 2 3 1 5"
  "4 2 3 5 1"
  "4 2 5 1 3"
  "4 2 5 3 1"
  "4 3 1 2 5"
  "4 3 1 5 2"
  "4 3 2 1 5"
  "4 3 2 5 1"
  "4 3 5 1 2"
  "4 3 5 2 1"
  "4 5 1 2 3"
  "4 5 1 3 2"
  "4 5 2 1 3"
  "4 5 2 3 1"
  "4 5 3 1 2"
  "4 5 3 2 1"
  "5 1 2 3 4"
  "5 1 2 4 3"
  "5 1 3 2 4"
  "5 1 3 4 2"
  "5 1 4 2 3"
  "5 1 4 3 2"
  "5 2 1 3 4"
  "5 2 1 4 3"
  "5 2 3 1 4"
  "5 2 3 4 1"
  "5 2 4 1 3"
  "5 2 4 3 1"
  "5 3 1 2 4"
  "5 3 1 4 2"
  "5 3 2 1 4"
  "5 3 2 4 1"
  "5 3 4 1 2"
  "5 3 4 2 1"
  "5 4 1 2 3"
  "5 4 1 3 2"
  "5 4 2 1 3"
  "5 4 2 3 1"
  "5 4 3 1 2"
  "5 4 3 2 1"
)

passed_4=0
total_4=0
passed_5=0
total_5=0
passed_2=0
total_2=0
passed_3=0
total_3=0
echo -e "${CYAN}$ascii_art${RESET}"
sleep 2


echo -e "${YELLOW}${BOLD}${UNDERLINE}Running tests for 2-number test cases:${RESET}"

for test_case in "${test_cases_2_numbers[@]}"; do
  result=$(./push_swap $test_case)
  instruction_count=$(count_instructions "$result")

  if [ "$instruction_count" -gt 2 ]; then
    echo -e "${RED}${BOLD}Test case '$test_case': Error (Instructions: $instruction_count)${RESET}"
  else
    passed_2=$((passed_2 + 1))
    echo -e "${GREEN}${BOLD}Test case '$test_case': OK (Instructions: $instruction_count)${RESET}"
  fi
  total_2=$((total_2 + 1))
done

# Run tests for 3-number test cases
echo -e "\n${YELLOW}${BOLD}${UNDERLINE}Running tests for 3-number test cases:${RESET}"

for test_case in "${test_cases_3_numbers[@]}"; do
  result=$(./push_swap $test_case)
  instruction_count=$(count_instructions "$result")

  if [ "$instruction_count" -gt 3 ]; then
    echo -e "${RED}${BOLD}Test case '$test_case': Error (Instructions: $instruction_count)${RESET}"
  else
    passed_3=$((passed_3 + 1))
    echo -e "${GREEN}${BOLD}Test case '$test_case': OK (Instructions: $instruction_count)${RESET}"
  fi
  total_3=$((total_3 + 1))
done

echo -e "${YELLOW}${BOLD}${UNDERLINE}Running tests for all 4-number permutations:${RESET}"

for test_case in "${test_cases_4_numbers[@]}"; do
  result=$(./push_swap $test_case)
  instruction_count=$(count_instructions "$result")
  
  if [ "$instruction_count" -gt 12 ]; then
    echo -e "${RED}${BOLD}Test case '$test_case': Enstraction Error (Instructions: $instruction_count)${RESET}"
  else
    passed_4=$((passed_4 + 1))
    echo -e "${GREEN}${BOLD}Test case '$test_case': OK (Instructions: $instruction_count)${RESET}"
  fi
  total_4=$((total_4 + 1))
done
echo -e "${YELLOW}${BOLD}${UNDERLINE}Running tests for all 5-number permutations:${RESET}"

for test_case in "${test_cases_5_numbers[@]}"; do
  result=$(./push_swap $test_case)
  instruction_count=$(count_instructions "$result")
  
  if [ "$instruction_count" -gt 12 ]; then
    echo -e "${RED}${BOLD}Test case '$test_case': Enstraction Error (Instructions: $instruction_count)${RESET}"
  else
    passed_5=$((passed_5 + 1))
    echo -e "${GREEN}${BOLD}Test case '$test_case': OK (Instructions: $instruction_count)${RESET}"
  fi
  total_5=$((total_5 + 1))
done
echo -e "\n${CYAN}${BOLD}Final Results:${RESET}"
echo -e "${GREEN}${BOLD}Tests Passed for 2-number cases: $passed_2 / $total_2 (${GREEN}$((passed_2 * 100 / total_2))%${RESET})"
echo -e "${GREEN}${BOLD}Tests Passed for 3-number cases: $passed_3 / $total_3 (${GREEN}$((passed_3 * 100 / total_3))%${RESET})"
echo -e "${GREEN}${BOLD}Tests Passed for 4-number cases: $passed_4 / $total_4 (${GREEN}$((passed_4 * 100 / total_4))%${RESET})"
echo -e "${GREEN}${BOLD}Tests Passed for 5-number cases: $passed_5 / $total_5 (${GREEN}$((passed_5 * 100 / total_5))%${RESET})"
total_passed=$((passed_2 + passed_3))
total_tests=$((total_2 + total_3))
echo -e "${GREEN}${BOLD}Total Passed: $total_passed / $total_tests (${GREEN}$((total_passed * 100 / total_tests))%${RESET})"
echo -e "\n${BRIGHT_YELLOW}${BOLD}Created by Ahbilla${RESET}"
