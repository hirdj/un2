# Implement an elementary chatbot for customer interaction
def elementary_chatbot():
    responses = {
        "greeting": "Welcome to our customer support! How can I assist you today?",
        "options": "Would you like help with account issues, product information, or something else?",
        "account_issues": "For account-related queries, please contact our support team at support@example.com.",
        "product_info": "Our products are designed to provide the best experience. You can find more details on our website.",
        "default": "I'm still learning. Please contact our support team for further assistance."
    }

    def chatbot_response(user_input):
        if "account" in user_input:
            return responses["account_issues"]
        elif "product" in user_input:
            return responses["product_info"]
        else:
            return responses["default"]

    print(responses["greeting"])
    print(responses["options"])

    while True:
        user_input = input("User: ")
        if user_input.lower() == "exit":
            print("Thank you for using our chatbot. Have a great day!")
            break
        else:
            print("Chatbot:", chatbot_response(user_input))

# Run the elementary chatbot
elementary_chatbot()