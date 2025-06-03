#pragma once

#include <vector>
#include <string>

namespace svd::exporters {

/**
 * @brief Represents exported SVD content
 */
class SvdExporterContent
{
public:
    SvdExporterContent(std::vector<uint8_t> content, std::string filename);
    ~SvdExporterContent() = default;
    
    // Copy and move constructors/assignment operators
    SvdExporterContent(const SvdExporterContent&) = default;
    SvdExporterContent& operator=(const SvdExporterContent&) = default;
    SvdExporterContent(SvdExporterContent&&) = default;
    SvdExporterContent& operator=(SvdExporterContent&&) = default;

    // Getters
    const std::vector<uint8_t>& getContent() const { return m_content; }
    const std::string& getFilename() const { return m_filename; }

private:
    std::vector<uint8_t> m_content;
    std::string m_filename;
};

} // namespace svd::exporters
