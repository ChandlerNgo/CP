bool contains012(const std::string& num) {
    return num.find("012") != std::string::npos;
}

void generateNumbers(int maxDigits) {
    std::vector<std::string> results;
    int maxLimit = 1;

    // Compute the maximum value based on the number of digits
    for (int i = 0; i < maxDigits; ++i) {
        maxLimit *= 3; // Since there are 3 digits (0, 1, 2)
    }

    // Generate numbers using base-3 representation
    for (int i = 0; i < maxLimit; ++i) {
        int value = i;
        std::string num;

        // Convert to base-3 (digits 0, 1, 2)
        for (int j = 0; j < maxDigits; ++j) {
            num = std::to_string(value % 3) + num;
            value /= 3;
        }

        // Remove leading zeros for proper formatting
        while (num.size() > 1 && num[0] == '0') {
            num.erase(0, 1);
        }

        results.push_back(num);
    }

    // Print all results
    for (const auto& number : results) {
        solve(number);
    }
}