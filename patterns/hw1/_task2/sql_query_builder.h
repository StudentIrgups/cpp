#pragma once

#include <string>
#include <vector>
#include <map>
#include <utility>

class SqlSelectQueryBuilder {
public:
    SqlSelectQueryBuilder& AddColumn(const std::string& column) {
        columns_.push_back(column);
        return *this;
    }

    SqlSelectQueryBuilder& AddFrom(const std::string& table) {
        from_table_ = table;
        return *this;
    }

    SqlSelectQueryBuilder& AddWhere(const std::string& key, 
                                    const std::string& value) {
        where_conditions_.emplace_back(key, value);
        return *this;
    }

    SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept {
        for (const auto& col : columns) {
            columns_.push_back(col);
        }
        return *this;
    }

    SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept {
        for (const auto& [key, value] : kv) {
            where_conditions_.emplace_back(key, value);
        }
        return *this;
    }

    std::string BuildQuery() const {
        std::string query = "SELECT ";

        if (columns_.empty()) {
            query += "*";
        } else {
            for (size_t i = 0; i < columns_.size(); ++i) {
                if (i > 0) query += ", ";
                query += columns_[i];
            }
        }

        if (!from_table_.empty()) {
            query += " FROM " + from_table_;
        }
        
        if (!where_conditions_.empty()) {
            query += " WHERE ";
            for (size_t i = 0; i < where_conditions_.size(); ++i) {
                if (i > 0) query += " AND ";
                query += where_conditions_[i].first + "=" 
                       + where_conditions_[i].second;
            }
        }

        query += ";";
        return query;
    }

private:
    std::vector<std::string> columns_;
    std::string from_table_;
    std::vector<std::pair<std::string, std::string>> where_conditions_;
};