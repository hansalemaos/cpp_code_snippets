#define _CRT_SECURE_NO_WARNINGS
#include <cstddef> // For offsetof
#include <cstdint>
#include <cstring> // For std::strcmp
#include <iostream>
#include <string>
#include <vector>

typedef struct result_struct
{
    int64_t index;
    size_t indent;
    std::string text;
    std::string resource_id;
    std::string clazz;
    std::string package;
    std::string content_desc;
    std::string checkable;
    std::string checked;
    std::string clickable;
    std::string enabled;
    std::string focusable;
    std::string focused;
    std::string scrollable;
    std::string long_clickable;
    std::string password;
    std::string selected;
    std::string visible_to_user;
    std::string bounds;
    std::string drawing_order;
    std::string hint;
    std::string display_id;
    int64_t line_index;
    std::vector<int64_t> children;
    std::vector<int64_t> parents;
    int32_t aa_center_x;
    int32_t aa_center_y;
    int32_t aa_area;
    int32_t aa_width;
    int32_t aa_height;
    int32_t aa_start_x;
    int32_t aa_start_y;
    int32_t aa_end_x;
    int32_t aa_end_y;
    int32_t aa_is_square;
    float_t aa_w_h_relation;
} result_struct;

// The struct

// fields to check if data type is right before casting
enum FieldType
{
    FIELD_UINT8,
    FIELD_UINT16,
    FIELD_UINT32,
    FIELD_UINT64,
    FIELD_INT8,
    FIELD_INT16,
    FIELD_INT32,
    FIELD_INT64,
    FIELD_SIZE_T,
    FIELD_STRING,
    FIELD_VECTOR_INT64,
    FIELD_FLOAT,
    FIELD_UNKNOWN
};

// A helper struct for metadata
struct field_info
{
    const char *field_name;
    std::size_t offset;
    FieldType field_type;
};

// Metadata table for each field of result_struct
static field_info result_struct_fields[] = {{"index", offsetof(result_struct, index), FIELD_INT64},
                                            {"indent", offsetof(result_struct, indent), FIELD_SIZE_T},
                                            {"text", offsetof(result_struct, text), FIELD_STRING},
                                            {"resource_id", offsetof(result_struct, resource_id), FIELD_STRING},
                                            {"clazz", offsetof(result_struct, clazz), FIELD_STRING},
                                            {"package", offsetof(result_struct, package), FIELD_STRING},
                                            {"content_desc", offsetof(result_struct, content_desc), FIELD_STRING},
                                            {"checkable", offsetof(result_struct, checkable), FIELD_STRING},
                                            {"checked", offsetof(result_struct, checked), FIELD_STRING},
                                            {"clickable", offsetof(result_struct, clickable), FIELD_STRING},
                                            {"enabled", offsetof(result_struct, enabled), FIELD_STRING},
                                            {"focusable", offsetof(result_struct, focusable), FIELD_STRING},
                                            {"focused", offsetof(result_struct, focused), FIELD_STRING},
                                            {"scrollable", offsetof(result_struct, scrollable), FIELD_STRING},
                                            {"long_clickable", offsetof(result_struct, long_clickable), FIELD_STRING},
                                            {"password", offsetof(result_struct, password), FIELD_STRING},
                                            {"selected", offsetof(result_struct, selected), FIELD_STRING},
                                            {"visible_to_user", offsetof(result_struct, visible_to_user), FIELD_STRING},
                                            {"bounds", offsetof(result_struct, bounds), FIELD_STRING},
                                            {"drawing_order", offsetof(result_struct, drawing_order), FIELD_STRING},
                                            {"hint", offsetof(result_struct, hint), FIELD_STRING},
                                            {"display_id", offsetof(result_struct, display_id), FIELD_STRING},
                                            {"line_index", offsetof(result_struct, line_index), FIELD_INT64},
                                            {"children", offsetof(result_struct, children), FIELD_VECTOR_INT64},
                                            {"parents", offsetof(result_struct, parents), FIELD_VECTOR_INT64},
                                            {"aa_center_x", offsetof(result_struct, aa_center_x), FIELD_INT32},
                                            {"aa_center_y", offsetof(result_struct, aa_center_y), FIELD_INT32},
                                            {"aa_area", offsetof(result_struct, aa_area), FIELD_INT32},
                                            {"aa_width", offsetof(result_struct, aa_width), FIELD_INT32},
                                            {"aa_height", offsetof(result_struct, aa_height), FIELD_INT32},
                                            {"aa_start_x", offsetof(result_struct, aa_start_x), FIELD_INT32},
                                            {"aa_start_y", offsetof(result_struct, aa_start_y), FIELD_INT32},
                                            {"aa_end_x", offsetof(result_struct, aa_end_x), FIELD_INT32},
                                            {"aa_end_y", offsetof(result_struct, aa_end_y), FIELD_INT32},
                                            {"aa_is_square", offsetof(result_struct, aa_is_square), FIELD_INT32},
                                            {"aa_w_h_relation", offsetof(result_struct, aa_w_h_relation), FIELD_FLOAT},
                                            // Sentinel entry
                                            {nullptr, 0, FIELD_UNKNOWN}};

//--------------------------------------------------------------
// 1) A helper to find the metadata for a given field name
//--------------------------------------------------------------
const field_info *find_field_info(const char *name)
{
    for (int i = 0; result_struct_fields[i].field_name != nullptr; ++i)
    {
        if (std::strcmp(result_struct_fields[i].field_name, name) == 0)
        {
            return &result_struct_fields[i];
        }
    }
    return nullptr;
}

// string_view is ok here, as long as we are not destroying the string
std::string_view get_string_value(result_struct &rs, std::string &&field_name)
{
    const field_info *info = find_field_info(field_name.c_str());
    if (!info)
    {
        throw std::runtime_error("Field '" + field_name + "' not found.");
    }
    if (info->field_type == FIELD_STRING)
    {
        // God, forgive me
        auto *field{reinterpret_cast<std::string *>(reinterpret_cast<char *>(&rs) + info->offset)};
        return *field;
    }
    else
    {
        throw std::runtime_error("Field '" + field_name + "' was found, but is not the right data type.");
    }
}

// reference is ok here, as long as we are not destroying the vector
std::vector<int64_t> &get_vec_int64_value(result_struct &rs, std::string &&field_name)
{
    const field_info *info = find_field_info(field_name.c_str());
    if (!info)
    {
        throw std::runtime_error("Field '" + field_name + "' not found.");
    }
    if (info->field_type == FIELD_VECTOR_INT64)
    {
        auto *field{reinterpret_cast<std::vector<int64_t> *>(reinterpret_cast<char *>(&rs) + info->offset)};
        return *field;
    }
    else
    {
        throw std::runtime_error("Field '" + field_name + "' was found, but is not the right data type.");
    }
}

//--------------------------------------------------------------
// 3) Example usage
//--------------------------------------------------------------
int main()
{
    // Create and populate our struct instance
    result_struct rs{};
    rs.index = 1234;
    rs.indent = 2;
    rs.text = "Hello Reflection!";
    rs.bounds = "100,100,200,200";
    rs.children = {10, 11, 12};
    rs.parents = {99, 100};

    std::string_view boundstr{get_string_value(rs, "bounds")};
    std::cout << boundstr << std::endl;
    std::string_view textstr{get_string_value(rs, "text")};
    std::cout << textstr << std::endl;
    std::vector<int64_t> &parent_vector{get_vec_int64_value(rs, "parents")};
    std::cout << parent_vector.size() << std::endl;

    return 0;
}
