declare module "falzee" {
  /**
   * A simple blockchain implementation powered by the native Falzee addon.
   */
  export class Blockchain {
    constructor();

    /**
     * Add a new block to the blockchain.
     *
     * @param timestamp - The creation time of the block (usually in ISO format or custom string).
     * @param data - The data to store inside the block (can be a string, object, or any value).
     * @param nonce - A random number used for mining or block uniqueness.
     */
    addBlock(timestamp: string, data: any, nonce: number): void;

    /**
     * Get the entire blockchain as an array of blocks.
     *
     * @returns An array representing all blocks in the chain.
     */
    getChain(): any[];

    /**
     * Validate the integrity of the blockchain.
     *
     * @returns `true` if the blockchain is valid, otherwise `false`.
     */
    isValid(): boolean;
  }
}
