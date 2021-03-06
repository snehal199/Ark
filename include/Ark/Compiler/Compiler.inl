// return a code page between the finalized ones and the temporary ones
// based on index sent
inline std::vector<internal::Inst>& Compiler::page(int i)
{
    if (i >= 0)
        return m_code_pages[i];
    return m_temp_pages[-i - 1];
}

inline std::optional<std::size_t> Compiler::isOperator(const std::string& name)
{
    auto it = std::find(internal::Builtins::operators.begin(), internal::Builtins::operators.end(), name);
    if (it != internal::Builtins::operators.end())
        return std::distance(internal::Builtins::operators.begin(), it);
    return {};
}

inline std::optional<std::size_t> Compiler::isBuiltin(const std::string& name)
{
    auto it = std::find_if(internal::Builtins::builtins.begin(), internal::Builtins::builtins.end(),
        [&name](const std::pair<std::string, internal::Value>& element) -> bool {
            return name == element.first;
    });
    if (it != internal::Builtins::builtins.end())
        return std::distance(internal::Builtins::builtins.begin(), it);
    return {};
}