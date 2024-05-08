#include <iostream>
#include <unordered_map>

using namespace std;

class ElementaryChatbot {
public:
    ElementaryChatbot() {
        responses["greeting"] = "Welcome to our customer support! How can I assist you today?";
        responses["options"] = "Would you like help with account issues, product information, or something else?";
        responses["account_issues"] = "For account-related queries, please contact our support team at support@example.com.";
        responses["product_info"] = "Our products are designed to provide the best experience. You can find more details on our website.";
        responses["default"] = "I'm still learning. Please contact our support team for further assistance.";
    }

    string getResponse(const string& user_input) {
        if (user_input.find("account") != string::npos) {
            return responses["account_issues"];
        } else if (user_input.find("product") != string::npos) {
            return responses["product_info"];
        } else {
            return responses["default"];
        }
    }

    void start() {
        cout << responses["greeting"] << endl;
        cout << responses["options"] << endl;

        while (true) {
            string user_input;
            cout << "User: ";
            getline(cin, user_input);

            if (user_input == "exit") {
                cout << "Thank you for using our chatbot. Have a great day!" << endl;
                break;
            } else {
                cout << "Chatbot: " << getResponse(user_input) << endl;
            }
        }
    }

private:
    unordered_map<string, string> responses;
};

int main() {
    ElementaryChatbot chatbot;
    chatbot.start();
    return 0;
}
