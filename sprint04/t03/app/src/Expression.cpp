#include "Expression.h"
#include <numeric>

static int CheckOperandInCache(CacheStorage &cache,
                               std::string operand,
                               int op_ind) {
    int temp;

    if (!cache.HasValue(operand)) {
        try {
            temp = std::stoi(operand);
        }
        catch (std::invalid_argument &i) {
            throw std::invalid_argument(
                "invalid operand" + std::to_string(op_ind));
        }
        return temp;
    } else {
        return cache.GetValue(operand);
    }
}

static void CheckOutOfRange(CacheStorage &cache,
                            std::string oper,
                            int op_ind) {
    if (!cache.HasValue(oper)) {
        try {
            std::stoi(oper);
        }
        catch (std::out_of_range &o) {
            throw std::invalid_argument(
                "operand" + std::to_string(op_ind) + " out of range");
        }
        catch (std::invalid_argument &o) {}
    } else {
        if (cache.GetValue(oper) >= std::numeric_limits<int>::max())
            throw std::invalid_argument(
                "operand" + std::to_string(op_ind) + " out of range");
    }
}

static char CheckOperation(std::string operation) {
    if (!operation.find('+') && !operation.find('-') && !operation.find('*')
        && !operation.find('/'))
        throw std::invalid_argument("invalid operation");
    else
        return operation[0];
}

static void CheckDivisionByZero(CacheStorage &cache,
                                std::string op2,
                                std::string operation) {
    bool validInput = false;

    if (!cache.HasValue(op2)) {
        try {
            validInput =
                std::stoi(op2) == 0 && operation.find('/') != std::string::npos;
        }
        catch (std::out_of_range &o) {
            throw std::out_of_range("operand2 out of range");
        }
        catch (std::invalid_argument &o) {}
        if (validInput)
            throw std::invalid_argument("division by zero");
    } else {
        validInput = cache.GetValue(op2) == 0 && operation.find('/');
        if (validInput)
            throw std::invalid_argument("division by zero");
    }
}

template<typename Operation>
static int CheckOverflow(int left, int right, Operation &&op) {
    if (op(static_cast<long long>(left), static_cast<long long>(right))
        > std::numeric_limits<int>::max() ||
        op(static_cast<long long>(left), static_cast<long long>(right))
            <= std::numeric_limits<int>::min())
        throw std::overflow_error(
            "Your expression has too big result for out small int");
    return op(left, right);
}

static Expression::Operations GetOperEnum(char op) {
    if (op == '+')
        return Expression::Operations::Add;
    else if (op == '-')
        return Expression::Operations::Substract;
    else if (op == '*')
        return Expression::Operations::Multiply;
    else if (op == '/')
        return Expression::Operations::Division;
    else
        throw std::invalid_argument("invalid operation");
}

Expression::Expression(CacheStorage &store, std::string expr) : cache(store) {
    std::smatch match;
    bool valInput = std::regex_match(expr, match, std::regex(regular));

    CheckDivisionByZero(cache, match.str(3), match.str(2));
    if (!valInput)
        throw std::invalid_argument("invalid input");
    operation = GetOperEnum(CheckOperation(match.str(2)));
    CheckOutOfRange(cache, match.str(1), 1);
    op1 = CheckOperandInCache(cache, match.str(1), 1);
    op2 = CheckOperandInCache(cache, match.str(3), 2);
    rvalue = match.str(4);
    CheckOutOfRange(cache, match.str(3), 2);
}

Expression::Operations Expression::GetOperation() {
    return operation;
}

int Expression::GetOperand1() {
    return op1;
}

int Expression::GetOperand2() {
    return op2;
}

std::string Expression::GetRvalue() {
    return rvalue;
}

int Expression::Evaluate() {
    int result;

    if (operation == Expression::Operations::Add)
        result = CheckOverflow(op1, op2, [](long long op1, long long op2) {
          return op1 + op2;
        });
    else if (operation == Expression::Operations::Substract)
        result = CheckOverflow(op1, op2, [](long long op1, long long op2) {
          return op1 - op2;
        });
    else if (operation == Expression::Operations::Multiply)
        result = CheckOverflow(op1, op2, [](long long op1, long long op2) {
          return op1 * op2;
        });
    else if (operation == Expression::Operations::Division)
        result = CheckOverflow(op1, op2, [](long long op1, long long op2) {
          return op1 / op2;
        });
    if (rvalue.empty()) {
        return result;
    } else {
        cache.StoreValue(rvalue, result);
        return result;
    }
}
