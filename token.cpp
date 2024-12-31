#include "token.h"
#include <vector>
#include <algorithm>
#include <cctype>

// 解析命令和参数
std::vector<std::string> Token::parseCommand(const std::string& input) {
    std::vector<std::string> tokens;
    std::string token;
    bool inQuotes = false;
    for (char ch : input) {
        if (ch == '"') {
            inQuotes = !inQuotes;
        } else if (ch == ' ' && !inQuotes) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        } else {
            token += ch;
        }
    }
    if (!token.empty()) {
        tokens.push_back(token);
    }
    return tokens;
}

// 验证命令是否合法
bool Token::isValidCommand(const std::string& command) {
    const std::vector<std::string> validCommands = {
        "quit", "exit", "su", "logout", "register", "passwd", "useradd", "delete",
        "show", "buy", "select", "modify", "import", "log", "report"
    };
    return std::find(validCommands.begin(), validCommands.end(), command) != validCommands.end();
}

// 验证用户ID是否合法
bool Token::isValidUserID(const std::string& userID) {
    return !userID.empty() && userID.find(' ') == std::string::npos;
}

// 验证密码是否合法
bool Token::isValidPassword(const std::string& password) {
    return !password.empty() && password.find(' ') == std::string::npos;
}

// 验证用户名是否合法
bool Token::isValidUsername(const std::string& username) {
    return !username.empty();
}

// 验证权限是否合法
bool Token::isValidPrivilege(const std::string& privilege) {
    for (char ch : privilege) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

// 验证ISBN是否合法
bool Token::isValidISBN(const std::string& isbn) {
    return !isbn.empty() && isbn.find(' ') == std::string::npos;
}

// 验证书名是否合法
bool Token::isValidBookName(const std::string& bookName) {
    return !bookName.empty();
}

// 验证作者是否合法
bool Token::isValidAuthor(const std::string& author) {
    return !author.empty();
}

// 验证关键词是否合法
bool Token::isValidKeyword(const std::string& keyword) {
    return !keyword.empty();
}

// 验证价格是否合法
bool Token::isValidPrice(const std::string& price) {
    bool hasDecimal = false;
    for (char ch : price) {
        if (!isdigit(ch) && ch != '.') {
            return false;
        }
        if (ch == '.') {
            if (hasDecimal) {
                return false;
            }
            hasDecimal = true;
        }
    }
    return true;
}

// 验证数量是否合法
bool Token::isValidQuantity(const std::string& quantity) {
    for (char ch : quantity) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

// 验证总成本是否合法
bool Token::isValidTotalCost(const std::string& totalCost) {
    bool hasDecimal = false;
    for (char ch : totalCost) {
        if (!isdigit(ch) && ch != '.') {
            return false;
        }
        if (ch == '.') {
            if (hasDecimal) {
                return false;
            }
            hasDecimal = true;
        }
    }
    return true;
}