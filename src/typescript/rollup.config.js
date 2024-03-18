import typescript from 'rollup-plugin-typescript2'
import { terser } from 'rollup-plugin-terser'

export default [
    {
        input: 'src/index.ts',
        output: {
            file: 'lib/standardized-vessel-dataset.js',
            format: 'cjs',
        },
        plugins: [typescript(), terser()],
    },
]
