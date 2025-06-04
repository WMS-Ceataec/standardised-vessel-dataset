#include "svd/exporters/svd_exporter_content.hpp"

namespace svd::exporters {

SvdExporterContent::SvdExporterContent(std::vector<uint8_t> content, std::string filename)
    : m_content(std::move(content)), m_filename(std::move(filename))
{
}

} // namespace svd::exporters
