#!/bin/bash

# Script de test complet pour ScalarConverter
# Couleurs pour l'affichage
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

PROG="./Conversion_of_scalar_types"
PASSED=0
FAILED=0

echo "========================================="
echo "TESTS SCALAR CONVERTER - cpp_06/ex00"
echo "========================================="
echo ""

# Fonction de test
test_case() {
    local input="$1"
    local description="$2"
    echo -e "${YELLOW}Test:${NC} $description"
    echo "Input: $input"
    $PROG "$input"
    echo ""
}

# Fonction de test avec vérification d'output attendu
test_with_expected() {
    local input="$1"
    local expected_char="$2"
    local expected_int="$3"
    local expected_float="$4"
    local expected_double="$5"
    local description="$6"
    
    echo -e "${YELLOW}Test:${NC} $description (input: $input)"
    
    output=$($PROG "$input" 2>&1)
    
    # Vérification ligne par ligne
    char_line=$(echo "$output" | grep "^char:")
    int_line=$(echo "$output" | grep "^int:")
    float_line=$(echo "$output" | grep "^float:")
    double_line=$(echo "$output" | grep "^double:")
    
    all_match=true
    
    if [[ "$char_line" == "char: $expected_char" ]]; then
        echo -e "  ${GREEN}✓${NC} char: $expected_char"
    else
        echo -e "  ${RED}✗${NC} char: Expected '$expected_char', got '$char_line'"
        all_match=false
    fi
    
    if [[ "$int_line" == "int: $expected_int" ]]; then
        echo -e "  ${GREEN}✓${NC} int: $expected_int"
    else
        echo -e "  ${RED}✗${NC} int: Expected '$expected_int', got '$int_line'"
        all_match=false
    fi
    
    if [[ "$float_line" == "float: $expected_float" ]]; then
        echo -e "  ${GREEN}✓${NC} float: $expected_float"
    else
        echo -e "  ${RED}✗${NC} float: Expected '$expected_float', got '$float_line'"
        all_match=false
    fi
    
    if [[ "$double_line" == "double: $expected_double" ]]; then
        echo -e "  ${GREEN}✓${NC} double: $expected_double"
    else
        echo -e "  ${RED}✗${NC} double: Expected '$expected_double', got '$double_line'"
        all_match=false
    fi
    
    if [ "$all_match" = true ]; then
        ((PASSED++))
    else
        ((FAILED++))
    fi
    echo ""
}

echo "========================================="
echo "EXEMPLES DE LA CONSIGNE (OBLIGATOIRES)"
echo "========================================="
echo ""

test_with_expected "0" "Non displayable" "0" "0.0f" "0.0" "Exemple consigne 1"
test_with_expected "nan" "impossible" "impossible" "nanf" "nan" "Exemple consigne 2"
test_with_expected "42.0f" "'*'" "42" "42.0f" "42.0" "Exemple consigne 3"

echo "========================================="
echo "TESTS CHAR LITERALS"
echo "========================================="
echo ""

test_case "'c'" "Char literal 'c'"
test_case "'a'" "Char literal 'a'"
test_case "' '" "Char literal espace"

echo "========================================="
echo "TESTS INT LITERALS"
echo "========================================="
echo ""

test_case "-42" "Int négatif"
test_case "42" "Int positif"
test_case "0" "Zero"

echo "========================================="
echo "TESTS FLOAT LITERALS"
echo "========================================="
echo ""

test_case "0.0f" "Float zero"
test_case "-4.2f" "Float négatif"
test_case "4.2f" "Float positif"

echo "========================================="
echo "TESTS DOUBLE LITERALS"
echo "========================================="
echo ""

test_case "0.0" "Double zero"
test_case "-4.2" "Double négatif"
test_case "4.2" "Double positif"

echo "========================================="
echo "TESTS PSEUDO-LITERALS FLOAT"
echo "========================================="
echo ""

test_with_expected "nanf" "impossible" "impossible" "nanf" "nan" "nanf"
test_with_expected "+inff" "impossible" "impossible" "inff" "inf" "+inff"
test_with_expected "-inff" "impossible" "impossible" "-inff" "-inf" "-inff"

echo "========================================="
echo "TESTS PSEUDO-LITERALS DOUBLE"
echo "========================================="
echo ""

test_with_expected "nan" "impossible" "impossible" "nanf" "nan" "nan"
test_with_expected "+inf" "impossible" "impossible" "inff" "inf" "+inf"
test_with_expected "-inf" "impossible" "impossible" "-inff" "-inf" "-inf"

echo "========================================="
echo "TESTS LIMITES INT"
echo "========================================="
echo ""

test_case "2147483647" "INT_MAX"
test_case "-2147483648" "INT_MIN"
test_case "2147483648" "INT_MAX + 1 (overflow)"
test_case "-2147483649" "INT_MIN - 1 (underflow)"

echo "========================================="
echo "TESTS LIMITES CHAR"
echo "========================================="
echo ""

test_case "32" "Premier char affichable (espace)"
test_case "126" "Dernier char affichable (~)"
test_case "127" "DEL (non-affichable)"
test_case "31" "Char non-affichable"
test_case "128" "Au-dessus limite char"
test_case "-129" "En-dessous limite char"

echo "========================================="
echo "TESTS OVERFLOW FLOAT/DOUBLE"
echo "========================================="
echo ""

test_with_expected "999999999999999999999999999999999999999999999999999999999f" "impossible" "impossible" "inff" "inf" "Overflow float vers infinity"
test_with_expected "-999999999999999999999999999999999999999999999999999999999f" "impossible" "impossible" "-inff" "-inf" "Overflow float vers -infinity"

echo "========================================="
echo "TESTS ENTRÉES INVALIDES"
echo "========================================="
echo ""

echo -e "${YELLOW}Test:${NC} Entrée invalide 'abc'"
output=$($PROG "abc" 2>&1)
if [[ "$output" == *"Invalid input"* ]] || [[ "$output" == *"Error"* ]]; then
    echo -e "${GREEN}✓${NC} Rejeté correctement: $output"
    ((PASSED++))
else
    echo -e "${RED}✗${NC} Devrait être rejeté"
    ((FAILED++))
fi
echo ""

echo -e "${YELLOW}Test:${NC} Entrée invalide '12.34.56'"
output=$($PROG "12.34.56" 2>&1)
if [[ "$output" == *"Invalid input"* ]] || [[ "$output" == *"Error"* ]]; then
    echo -e "${GREEN}✓${NC} Rejeté correctement: $output"
    ((PASSED++))
else
    echo -e "${RED}✗${NC} Devrait être rejeté"
    ((FAILED++))
fi
echo ""

echo "========================================="
echo "TESTS PRÉCISION DÉCIMALE"
echo "========================================="
echo ""

test_case "42.42f" "Précision float (arrondi à .1)"
test_case "42.99" "Précision double (arrondi à .1)"
test_case "0.1f" "Petit nombre float"

echo "========================================="
echo "RÉSUMÉ DES TESTS"
echo "========================================="
echo ""
echo -e "${GREEN}Tests réussis:${NC} $PASSED"
echo -e "${RED}Tests échoués:${NC} $FAILED"
echo ""

if [ $FAILED -eq 0 ]; then
    echo -e "${GREEN}✓ TOUS LES TESTS SONT PASSÉS !${NC}"
    exit 0
else
    echo -e "${RED}✗ Certains tests ont échoué${NC}"
    exit 1
fi
